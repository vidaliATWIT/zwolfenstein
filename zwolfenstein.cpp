#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>

//Screen dimension constants
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

// Start up SDL and create window
bool init();

// Loads media
bool loadMedia();

// Frees media and shuts down SDL
void close();

// The window we'll be rendering to
SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;
// The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

// Map variables
const int mapWidth = 24;
const int mapHeight = 24;

// Color Constants
const int RED[4] = {0xFF, 0x00, 0x00, 0xFF};
const int GREEN[4] = {0x00, 0xFF, 0x00, 0xFF};
const int BLUE[4] = {0x00, 0x00, 0xFF, 0xFF};
const int WHITE[4] = {0xFF, 0xFF, 0xFF, 0xFF};
const int YELLOW[4] = {0xFF, 0xFF, 0x00, 0xFF};

int color[4] = {0x00, 0x00, 0x00, 0xFF};

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};



bool init()
{
    // Initialization flag
    bool success = true;

    // Initialize SDL
    if (SDL_Init (SDL_INIT_VIDEO) < 0) 
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else 
    {
        gWindow = SDL_CreateWindow( "Zwolfenstein", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else 
        {
            // Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1,  SDL_RENDERER_PRESENTVSYNC);
            if (gRenderer==NULL) 
            {
                printf("Rendered could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                // Init render color
                SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);

            }
            // Get Window surface
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }
    return success;
}

bool loadMedia()
{
    // Loading success flag
    bool success = true;

    // Nothing to load
    return success;
}   

void close()
{
    // Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gRenderer=NULL;
    gWindow=NULL;

    // Quit SDL subsystem
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char* args[])
{
    double posX = 22, posY=12; // Player position
    double dirX = -1, dirY = 0; // Player look directions
    double planeX = 0, planeY = 0.66; // Camera plane

    // vars for calculating FPS
    double time = 0;
    double oldTime = 0;

    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() ) //Unused
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            // Main loop flag
            bool quit = false;

            // Event handler
            SDL_Event e;

            // Game Loop
            while (!quit)
            {
                // Clear screen
                SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
                SDL_RenderClear(gRenderer);

                // Raycast loop
                for (int x = 0; x < SCREEN_WIDTH; x++)
                {
                    // calculate ray pos and direction
                    double cameraX = 2 * x / double(SCREEN_WIDTH) - 1; // X coordinate in camera space
                    double rayDirX = dirX + planeX * cameraX;
                    double rayDirY = dirY + planeY * cameraX;

                    // Which cell of the map we're in
                    int mapX = int(posX);
                    int mapY = int(posY);

                    // Length of the ray from current pos to next x, or y edge
                    double sideDistX;
                    double sideDistY;

                    // Length of ray from one x or y edge to next
                    double deltaDistX = (rayDirX == 0) ? 1e30 : std::abs(1 / rayDirX);
                    double deltaDistY = (rayDirY == 0) ? 1e30 : std::abs(1 / rayDirY);
                    double perpWallDist;

                    // What direction to step in (+1 or -1)
                    int stepX;
                    int stepY;

                    int hit = 0; // Was there a wall hit?
                    int side; // was a NS or a EW wall hit?

                    // Calculate step and initial sideDist
                    if (rayDirX < 0)
                    {
                        stepX = -1;
                        sideDistX = (posX - mapX) * deltaDistX;
                    }
                    else 
                    {
                        stepX = 1;
                        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
                    }
                    if (rayDirY < 0)
                    {
                        stepY = -1;
                        sideDistY = (posY - mapY) * deltaDistY;
                    }
                    else
                    {
                        stepY = 1;
                        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
                    }

                    // DDA Calculation
                    while (hit == 0)
                    {
                        // Move to next map cell, in x or y
                        if (sideDistX < sideDistY)
                        {
                            sideDistX += deltaDistX;
                            mapX+=stepX;
                            side = 0;
                        }
                        else
                        {
                            sideDistY += deltaDistY;
                            mapY += stepY;
                            side = 1;
                        }
                        // Check if ray has hit a wall
                        if (worldMap[mapX][mapY] > 0) hit = 1;
                    }
                    // Calculate distance from camera plane to avoid fish-eye
                    if (side == 0) perpWallDist = (sideDistX - deltaDistX);
                    else perpWallDist = (sideDistY - deltaDistY);

                    // Calculate the height of the line to draw on screen
                    int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

                    //calculate the lowest and highest pixel to fill in current line
                    int drawStart = -lineHeight/2 + SCREEN_HEIGHT / 2;
                    if (drawStart < 0) drawStart = 0;
                    int drawEnd = lineHeight/2 + SCREEN_HEIGHT/2;
                    if (drawEnd >= SCREEN_HEIGHT) drawEnd = SCREEN_HEIGHT - 1;

                    for (int i = 0; i<3; i++) color[i] = 0x00;

                    switch(worldMap[mapX][mapY])
                    {
                        case 1: for (int i = 0; i<4; i++) color[i] = RED[i]; break;
                        case 2: for (int i = 0; i<4; i++) color[i] = GREEN[i]; break;
                        case 3: for (int i = 0; i<4; i++) color[i] = BLUE[i]; break;
                        case 4: for (int i = 0; i<4; i++) color[i] = WHITE[i]; break;
                        default: for (int i = 0; i<4; i++) color[i] = YELLOW[i]; break;
                    }
                    if (side == 1) 
                    {
                        for (int i = 0; i < 3; i++) 
                        { 
                            color[i]=color[i]/2;
                        }
                    }
                    
                    // Draw the line
                    SDL_SetRenderDrawColor(gRenderer, color[0], color[1], color[2], color[3]);
                    SDL_RenderDrawLine(gRenderer, x, drawStart, x, drawEnd);
                }

                // Timing for input and FPS counter
                oldTime = time;
                time = SDL_GetTicks();
                double frameTime = (time - oldTime) / 1000.0;

                // speed modifiers
                double moveSpeed = frameTime * 5.0;
                double rotSpeed = frameTime * 3.0;

                SDL_RenderPresent(gRenderer);

                while (SDL_PollEvent(&e) != 0)
                {
                    // User requests quit
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                     else if (e.type == SDL_KEYDOWN)
                    {
                        double oldDirX;
                        double oldPlaneX;
                        double oldDirY;
                        double oldPlaneY;

                        if (e.key.keysym.sym == SDLK_UP)
                        {
                            printf("UP\n");
                            if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
                            if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
                        }
                        if (e.key.keysym.sym == SDLK_DOWN)
                        {
                            printf("DOWN\n");
                            if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
                            if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
                        }
                        if (e.key.keysym.sym == SDLK_RIGHT)
                        {
                            printf("RIGHT\n");
                            oldDirX = dirX;
                            dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
                            dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
                            oldPlaneX = planeX;
                            planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
                            planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
                        }
                        if (e.key.keysym.sym == SDLK_LEFT)
                        {
                            printf("LEFT\n");
                            oldDirX = dirX;
                            dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
                            dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
                            oldPlaneX = planeX;
                            planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
                            planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
                        }
                    }
                }
            }
        }
    }

    close();
    return 0;
}