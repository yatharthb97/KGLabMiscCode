#pragma once


#include "./submodules/vector.hpp"
#include<vector>
#include<array>


class Particle
{
public:

	unsigned int partid;
	V pos; 		         	//Position Vector
   	V init_pos;          	//Initial Position
	double D = 3.0;      	//Diffusion Rate
	double qm_yield = 0.8; 	//Emmission base probablity
	bool InVol = false;     // Is the particle in the observation Volume ?
	
	unsigned long int last_flash = 0;  //Time of last flash
	//unsigned long int creation_t = 0;  //Time of Creation
	
	unsigned int FlashCount;  //Number of times the molecule is flashed
	bool bleached = false;    //Is the molecule bleached?

	unsigned int bleach_after;


	#if defined(FCS_PER_PART_STATS) //Calculate stats for every Particle
		double dist = 0;
		double dist_sq = 0;
	#endif


  //Default Constructor
  Particle(unsigned int partid, V &pos): partid(partid), pos(pos), init_pos(pos)
  {}


/*  static unsigned int BleachedCount(const partlist_t &partlist)
  {
  	unsigned int count = 0;
  	for(auto &part : partlist)
  	{
  		count += part.bleached;
  	}

  	return count;
  } //End of BleachedCount()*/



  void __attribute__((always_inline)) Flash() //[[always_inline]]
  {
  	
  	//A
  	#if FCS_PER_PART_STATS == 1
  		this->FlashCount++;
  	#endif

  	//B
  	#if FCS_BLEACHING == 1
	  	this->internalflashCounter--;
	  	if(internalflashCounter == 0)
	  	{
	  		bleached =!bleached; //Toggle
	  		internalflashCounter = Particle::bleach_after;
	  	}
  	#endif
  } // End of Flash()

}; //End of class Particle
//static Particle::bleach_after = 5;


//Typename aliases
using partlist_t = std::vector<Particle>;

template<std::size_t N>
using partlist_ft = std::array<Particle, N>;