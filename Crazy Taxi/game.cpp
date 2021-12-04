#include "game.hpp"
#include "CrazyTaxi.hpp"
#include<vector>
Mix_Music *bgMusic = NULL;
Mix_Music *menuMusic = NULL;
Mix_Chunk *gCrash = NULL;
Mix_Chunk *gGameOver = NULL;
Mix_Chunk *gTaxiStart = NULL;
Mix_Chunk *gTaxiHorn = NULL;
void Game::rules(){
		screen = SDL_GetWindowSurface(gWindow);
		rules_called = true;
		maingame_called==false;
		SDL_FreeSurface( screen );		
}

void Game::maingame(){
		screen = SDL_GetWindowSurface(gWindow);
		rules_called = false;
		maingame_called = true;
		SDL_FreeSurface( screen );		
}

bool Game::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Star Wars", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	
	assets = loadTexture("assets5.png");
    gTexture = loadTexture("bgDay.jpg");
	if(assets==NULL || gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	bgMusic = Mix_LoadMUS( "wackyrace.wav" );
	if(bgMusic == NULL){
		printf("Unable to load music: %s \n", Mix_GetError());
		success = false;
	}
	menuMusic = Mix_LoadMUS( "music1.mp3");
	if(menuMusic == NULL){
		printf("Unable to load music: %s \n", Mix_GetError());
		success = false;
	}
	//Load sound effects
    gCrash = Mix_LoadWAV( "crash.wav" );
    if( gCrash == NULL )
    {
        printf( "Failed to load crash sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
	gTaxiStart = Mix_LoadWAV( "start.wav" );
    if( gTaxiStart == NULL )
    {
        printf( "Failed to load crash sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
	gTaxiHorn = Mix_LoadWAV( "horn.wav" );
    if( gTaxiHorn == NULL )
    {
        printf( "Failed to load crash sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

	return success;
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(assets);
	assets=NULL;
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	// free the music
	Mix_FreeMusic(bgMusic);
	Mix_FreeMusic(menuMusic);
	bgMusic = NULL;
	menuMusic = NULL;
	//Free the sound effects
    Mix_FreeChunk( gCrash );
    Mix_FreeChunk( gGameOver );
	Mix_FreeChunk( gTaxiStart );
	Mix_FreeChunk( gTaxiHorn );
    gCrash = NULL;
    gGameOver = NULL;
	gTaxiStart = NULL;
	gTaxiHorn = NULL;

	// Quit SDL subsystems
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

void Game::write(std::string keychar)
{
	cur_time = time(0) - start_time;

	int length_text, length_sentence, wpm, accuracy;
	int mistakes = 0;
	std::string text = "";
	cout << endl;
	//length_sentence = sentence.length();
	time_t start;
	cur_string += keychar;
	time_t end;
	string input;
	//cur_string += keychar;
	input = text + cur_string;

	//input = cur_time + "\n" + input;

	TTF_Init();

	TTF_Font *font = TTF_OpenFont("arial.ttf", 25);
	SDL_Color color = {0, 0, 0};
	SDL_Surface *surface = TTF_RenderText_Solid(font,
												input.c_str(), color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(gRenderer, surface);

	//cout << wpm << endl;
	//accuracy = 100 - ((mistakes / length_text) * 100);

	int texW = 10;
	int texH = 10;
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = {0, 50, texW, texH};

	SDL_RenderCopy(gRenderer, texture, NULL, &dstrect);

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	TTF_CloseFont(font);
	TTF_Quit();
}

void Game::run( )
{
	bool quit = false;
	SDL_Event e;

	CrazyTaxi CrazyTaxi(gRenderer, assets);
	while( !quit )
	{
		//Handle events on queue
		// write("5");
		while( SDL_PollEvent( &e ) != 0 )
		{

			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}

			if(e.type == SDL_MOUSEBUTTONDOWN){
			//this is a good location to add pigeon in linked list.
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
				// if (xMouse >= )
				// gTexture = loadTexture("hulogo.png");
				CrazyTaxi.createObject(xMouse, yMouse);
				if (xMouse>100 && xMouse<375 && yMouse>350 && yMouse<470){
					maingame();
					Mix_PauseMusic();
					Mix_PlayChannel( -1, gTaxiStart, 0);
					Mix_PlayMusic( bgMusic, 2 );
				}
				if (xMouse>660 && xMouse<930 && yMouse>375 && yMouse<470) rules();
			}
			else if (e.type == SDL_KEYDOWN){
				if (e.key.keysym.sym == SDLK_RIGHT)
					CrazyTaxi.rightArrow();
			
				if (e.key.keysym.sym == SDLK_LEFT)
					CrazyTaxi.leftArrow();
				if (e.key.keysym.sym == SDLK_f)
					Mix_PlayChannel( -1, gTaxiHorn, 0);
			}
		
		}
		// CrazyTaxi.probObjects();
		if (CrazyTaxi.s1.n == 0 && day == 1){
			gTexture = loadTexture("bgDay.jpg");
			day = 0;
		}
		else if (CrazyTaxi.s1.n == 1 && day == 0){
			gTexture = loadTexture("bgNight.jpg");
			day = 1;
		}

		SDL_RenderClear(gRenderer); //removes everything from renderer
		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************
		// CrazyTaxi.draw();
		// CrazyTaxi.drawObjects();
		if (maingame_called==false && rules_called==false && restartgame_called == false){
			CrazyTaxi.drawLogo();
			CrazyTaxi.drawStart();
			CrazyTaxi.drawRules();
			if( Mix_PlayingMusic() == 0 )
			{
				//Play the music
				Mix_PlayMusic( menuMusic, 2 );
			}
		}

		else if (maingame_called==true && rules_called==false && restartgame_called == false){
			if (Mix_PlayingMusic() == 0)
				Mix_PlayMusic( bgMusic, 2 );
			CrazyTaxi.probObjects();
			CrazyTaxi.drawObjects();
			if (CrazyTaxi.crashed){
				Mix_PlayChannel( -1, gCrash, 0 );
				CrazyTaxi.crashed = false;
			}
			if (CrazyTaxi.gameOver){
				maingame_called = false; restartgame_called = true;
				CrazyTaxi.gameOver = false;
				cout << "----------GAME OVER----------" << endl;
				cout << "Points: " << CrazyTaxi.points << endl;
			}
			// if (CrazyTaxi.stats()){
			// 	maingame_called = false; restartgame_called = true;
			// }
		} 
		else if (rules_called==true && maingame_called==false && restartgame_called == false) {
			CrazyTaxi.drawInstructions();
			CrazyTaxi.drawBack();

			if (e.type == SDL_MOUSEBUTTONDOWN){
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
				if (xMouse>50 && xMouse<200 && yMouse>100 && yMouse<200){
					rules_called=false;
					maingame_called=false;
				} 
			}
		}
		else if (restartgame_called == true && maingame_called == false && rules_called == false){
			CrazyTaxi.drawEnd();
			CrazyTaxi.drawRestart();
			if (e.type == SDL_MOUSEBUTTONDOWN){
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
				if (xMouse>425 && xMouse<695 && yMouse>400 && yMouse<495){
					restartgame_called=false;
					maingame_called=false;
					break;
				} 
			}
		}
		//****************************************************************
    	SDL_RenderPresent(gRenderer); //displays the updated renderer

	    SDL_Delay(50);	//causes sdl engine to delay for specified miliseconds
	}
	// delete CrazyTaxi;
	CrazyTaxi.deleteObj();

}
