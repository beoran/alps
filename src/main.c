
#include "alps.h"
#include <stdlib.h>

#define SCREEN_W 640
#define SCREEN_H 480


/*
* Returns a new AlpsVector
*/
AlpsVector alpsvector(double x, double y) {
  AlpsVector result = { x, y };
  return result;
}

/*
* Returns a new AlpsVector with the summed up components of a and b.
*/

AlpsVector alpsvector_add(AlpsVector v1 , AlpsVector v2) {
  return alpsvector(v1.x + v2.x, v1.y + v2.y);
}

char *alpsvector_inspect(AlpsVector vec)
{
    char *result=malloc(256); // overkill
    sprintf(result, "Vector<%.2lf %.2lf>", vec.x, vec.y);

    return result;
}

AlpsDrop * alpsdrop_init(AlpsDrop *drop, AlpsVector p, AlpsVector v) {
  drop->position = p;
  drop->velocity = v;
  return drop;
}


void alpsdrop_tick(AlpsDrop *drop) {
  drop->position = alpsvector_add(drop->position, drop->velocity);
}


int main_loop(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE   * queue) {
  int busy = 1;
  ALLEGRO_EVENT event;
  AlpsDrop drop;
  alpsdrop_init(&drop, alpsvector(120.0, 0.0), alpsvector(0.0, 3.0));
  
  while (busy) {
    alpsdrop_tick(&drop);
    while(al_get_next_event(queue, &event)) {
      if(event.type == ALLEGRO_EVENT_KEY_DOWN) { 
        switch(((ALLEGRO_KEYBOARD_EVENT*)&event)->keycode) {
          case ALLEGRO_KEY_ESCAPE:
             busy = 0;
          default:
            break;
        }
      }
    }
    /* Draw here: */
    al_clear_to_color(al_map_rgb(0,0,0));
    al_put_pixel(drop.position.x, drop.position.y, al_map_rgb(128,128,255));
    al_flip_display();
  }
  return busy;
}



int main(void) {
  ALLEGRO_DISPLAY       * display;
  ALLEGRO_EVENT_QUEUE   * queue;
  AlpsVector v1, v2;
  AlpsVector vr;
  v1 = alpsvector(10.0, 20.0);
  v1 = alpsvector(30.0, 40.0);
  vr = alpsvector_add(v1, v2);
  printf("Vector sum: %lf %lf\n", vr.x, vr.y);
  
  al_init();
  display = al_create_display(SCREEN_W, SCREEN_H);
  if(!display)  return 1;
  queue   = al_create_event_queue();
  if(!queue)    return 2;
  
  al_install_keyboard();
  al_install_mouse();
  al_register_event_source(queue, al_get_keyboard_event_source());
  al_register_event_source(queue, al_get_mouse_event_source());
  
  main_loop(display, queue);
  
  al_destroy_display(display);
  return 0;
}


