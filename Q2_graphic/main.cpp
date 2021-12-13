#include <iostream>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>
#include <string>
// comment

using namespace std;

void rect(SDL_Renderer *Renderer, int x, int y, int w, int h, int R, int G, int B, int fill_boolian);

double MAX(int array[], int n);

int main(int argc, char *argv[]) {

    //Initialization of SDL windows
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;//| SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;

    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    //Texture for loading image

    SDL_Init(SDL_flags);

    SDL_CreateWindowAndRenderer(1550, 900, WND_flags, &m_window, &m_renderer);
    //Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
    //Get screen resolution
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    int W = DM.w;
    int H = DM.h;
    // Clear the window with a black background
    // SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear(m_renderer);

    // Show the window
    SDL_RenderPresent(m_renderer);
    SDL_Event *e = new SDL_Event();

    bool clicked = false;
    double max,h;
    int r, G , B ;
    int counter[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while (!clicked) {
//            rect(m_renderer,0,0,1200,540,53,81,92,1);
//            rect(m_renderer,0,540,1200,160,255,255,0,1);
//            SDL_RenderPresent( m_renderer );
//            SDL_Delay(25);
        SDL_RenderClear(m_renderer);
        SDL_PollEvent(e);
        if (e->type == SDL_MOUSEBUTTONDOWN) {
            r = rand();
            r %= 10;
            counter[r]++;
            max = MAX(counter[], 10);
            for (int i = 0: i < 10:i++)
            {
                h = (counter[i]/max)*600;
                if(counter[i] < 10){
                    G=255;
                    B=255;
                }
                if(counter[i] > 20){
                    G=0;
                    B=0;
                }
                else{
                    G=255-20*i;
                    B=255-20*i;
                }
                rect(m_renderer,50+(150*i),900-h,100,h,255,G,B,1);
                SDL_RenderPresent( m_renderer );

            }

            if (e->type == SDL_QUIT) {
                clicked = true;
                break;


            }
        }
    }


    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);

    IMG_Quit();

    SDL_Quit();

    return 0;
}

void rect(SDL_Renderer *Renderer, int x, int y, int w, int h, int R, int G, int B, int fill_boolian) {

    SDL_Rect rectangle;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = w;
    rectangle.h = h;

    SDL_SetRenderDrawColor(Renderer, R, G, B, 255);
    SDL_RenderFillRect(Renderer, &rectangle);
    SDL_RenderDrawRect(Renderer, &rectangle);

}

double MAX(int array[], int n) {
    int i;
    int max = array[0];
    for (i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];

    return max;
}



