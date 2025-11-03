assets/musica.mp3 : assets/musica.wav
	ffmpeg -i assets/musica.wav -codec:a libmp3lame -qscale:a 2 assets/TylerSong3_Normal.mp3

bin/punteros : src/punteros.cpp	
	c++ src/punteros.cpp -o bin/punteros -I include

ejecutar : bin/punteros	
	./bin/punteros

bin/ejemplo : src/ejemplo.cpp
	c++ src/ejemplo.cpp -o bin/ejemplo -Iinclude -lftxui-screen

ejemplo : bin/ejemplo
	./bin/ejemplo

run : bin/animacion
	./bin/animacion

bin/animacion : src/animacion.cpp include/*.hpp
	@mkdir -p bin
	g++ -Iinclude -o bin/animacion src/animacion.cpp -lftxui-component -lftxui-dom -lftxui-screen