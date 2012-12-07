#ifndef ALPS_H_INCLUDED
#define ALPS_H_INCLUDED

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct AlpsVector_ AlpsVector;
typedef struct AlpsDrop_ AlpsDrop;
typedef struct AlpsShower_ AlpsShower;

struct AlpsVector_ {
  double x;
  double y;
};

struct AlpsDrop_ {
  AlpsVector position;
  AlpsVector velocity;
};

#define ALPS_SHOWER_DROPS 100


struct AlpsShower_ {
  int intensity;
  float abberation;
  AlpsVector velocity;
  AlpsDrop drops[ALPS_SHOWER_DROPS];
};


#ifdef THIS_IS_COMMENT

typedef struct AlpsVector_    AlpsVector;
typedef struct AlpsParticle_  AlpsParticle;



struct AlpsVector_ {
  double x, y;
};

struct AlpsCamera_ {
  AlpsPoint pos;
  AlpsPoint size;
};


/*
class AlpsPoint 
  attr_accessor :x
  attr_accessor :y
end

class AlpsParticle
  attr_accessor :position
  attr_accessor :velocity
  attr_accessor :acceleration
  attr_accessor :color
  attr_accessor :life
end

#
#
#
*/

struct AlpsParticle_ {
  AlpsVector_        pos;
  AlpsPoint         vel;
  AlpsPoint         acc;
  int               type;
  double            life;
  ALLEGRO_COLOR     color;
  ALLEGRO_BITMAP  * bitmap;
};



#endif


#endif
