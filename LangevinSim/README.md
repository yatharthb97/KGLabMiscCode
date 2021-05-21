
# Langvin Simulation Code








Probablity of flashing = P(Laser Pulsing) * P(PSF) * P(Inherent Quantum Yield)


Some Important Points:

•   *Uniform Spherical Mode* does not use PSF based probablity scaling. (Just Laser Pulse and Quantum Yield).
• *Uniform Spherical Mode* also ignores the Structure Factor arguement (sf) passed to the Veff Object.
• For *Uniform Spherical Mode* "PSF Exponents" and "PSF Normalization" are both set to zero.




## Compile via:

> g++ std=c++11 main.cpp -o langsim

## Run Via: 

> ./langsim


##Python Plot can be manually called by:

> ./Plots.py <path_to_box_directory>



## Update Scheme

>	part.pos.x += std::sqrt(2*part.D*dt)*gauss_dist(rnd.engine);
>   part.pos.y += std::sqrt(2*part.D*dt)*gauss_dist(rnd.engine);
>  	part.pos.z += std::sqrt(2*part.D*dt)*gauss_dist(rnd.engine);


## Issues: 
	• "last_plot.png" is not getting rendered in python. Output is blank white image.