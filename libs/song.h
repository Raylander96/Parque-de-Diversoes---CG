void loadSong ()
{
    atexit(Mix_CloseAudio);
    theme = Mix_LoadMUS("song/Ambient_Song.mp3");
}

void songPlay() {
	SDL_Init (SDL_INIT_AUDIO);
	loadSong();	
	Mix_PlayMusic(theme, -1);
	atexit (SDL_Quit);
}