/*
This code implements an interface to the FBGS sensing system
Copyright (C) 2022 Sven Lilge, Continuum Robotics Laboratory, University of Toronto Mississauga
*/

//includes
#include <iostream>
#include <vector>
#include <string>
#include <Eigen/Dense>


#include <boost/array.hpp>
#include <boost/asio.hpp>

#include "fbgs-sensing/shape_sensing_interface.h"
#include "fbgs-sensing/illumisense_interface.h"

//defines
#define SERVER_ADDRESS "192.168.1.11"
#define PORT_NUMBER "5001" //Default port number for Shape Sensing
//#define PORT_NUMBER "2055" //Default port number for Illumisense
//#define CALIB_FILE "/home/sven/Downloads/PR2022_14_53_01_S01 - calib.txt"

#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

int main(int argc, char **argv)
{
	

	//Example code for Shape Sensing Interface
	
	ShapeSensingInterface interface(SERVER_ADDRESS,PORT_NUMBER);
	
	if(!interface.connect())
        return 0;

    std::cout << "connected !" << std::endl;
    const unsigned int max_count = 1000;
    std::vector<unsigned int> sample_numbers(max_count);
    unsigned int count = 0;
    while(count<max_count)
	{
		if(interface.nextSampleReady())
		{
            ShapeSensingInterface::Sample sample;
			
			if(interface.readNextSample(sample))
			{
                sample_numbers[count] = sample.sample_number;
                count++;
//                std::cout << sample.num_channels << std::endl;
//                std::cout << sample.num_sensors << std::endl << std::endl;
				
//				for(int i = 0; i < sample.num_channels; i++)
//				{
//					std::cout << sample.channels.at(i).channel_number << std::endl;
//					std::cout << sample.channels.at(i).num_gratings << std::endl << std::endl;
					
//					std::cout << sample.channels.at(i).error_status(0) << std::endl;
//					std::cout << sample.channels.at(i).error_status(1) << std::endl;
//					std::cout << sample.channels.at(i).error_status(2) << std::endl;
//					std::cout << sample.channels.at(i).error_status(3) << std::endl << std::endl;
					
//					for(int j = 0; j < sample.channels.at(i).num_gratings; j++)
//					{
//						std::cout << sample.channels.at(i).peak_wavelengths(j) << " " << sample.channels.at(i).peak_powers(j) << std::endl;
//					}
//					std::cout << std::endl;
//				}
				
//				for(int i = 0; i < sample.num_sensors; i++)
//				{
//					std::cout << sample.sensors.at(i).num_curv_points << std::endl;
//					std::cout << sample.sensors.at(i).num_shape_points << std::endl << std::endl;
					
					
//					for(int j = 0; j < sample.sensors.at(i).num_curv_points; j++)
//					{
//						std::cout << sample.sensors.at(i).kappa(j) << " " << sample.sensors.at(i).phi(j) << std::endl;
//					}
//					std::cout << std::endl;
					
					
//					for(int j = 0; j < sample.sensors.at(i).num_shape_points; j++)
//					{
//						std::cout << sample.sensors.at(i).shape.row(j) << " " << sample.sensors.at(i).arc_length(j) << std::endl;
//					}
//					std::cout << std::endl;
					
//				}
			}
			
			
			
			
		}
	
	
	}


    std::vector<unsigned int> steps;
    for(unsigned int i=1; i<sample_numbers.size(); i++){
        unsigned int diff = sample_numbers[i] - sample_numbers[i-1];
        steps.push_back(diff);
        std::cout << "diff : " << diff << "\n";
    }


    // Set the size of output image to 1200x780 pixels
    plt::figure_size(1200, 780);
    // Plot line from given x and y data. Color is selected automatically.
    plt::plot(steps);
    // Add graph title
    plt::title("Samples steps");

    plt::show();




	
	
	
	//Example code for IllumiSense Interface
	
	//IllumiSenseInterface interface(SERVER_ADDRESS,PORT_NUMBER,CALIB_FILE);
	
	//if(!interface.connect())
	//	return 0;
	//
	//while(1)
	//{
	//	if(interface.nextSampleReady())
	//	{
	//		IllumiSenseInterface::Sample sample;
	//		
	//		if(interface.readNextSample(sample))
	//		{
	//			std::cout << sample.sample_number << std::endl;
	//			std::cout << sample.num_channels << std::endl;
	//			std::cout << sample.num_sensors << std::endl << std::endl;
	//			
	//			for(int i = 0; i < sample.num_channels; i++)
	//			{
	//				std::cout << sample.channels.at(i).channel_number << std::endl;
	//				std::cout << sample.channels.at(i).num_gratings << std::endl << std::endl;
	//				
	//				std::cout << sample.channels.at(i).error_status(0) << std::endl;
	//				std::cout << sample.channels.at(i).error_status(1) << std::endl;
	//				std::cout << sample.channels.at(i).error_status(2) << std::endl;
	//				std::cout << sample.channels.at(i).error_status(3) << std::endl << std::endl;
	//				
	//				for(int j = 0; j < sample.channels.at(i).num_gratings; j++)
	//				{
	//					std::cout << sample.channels.at(i).peak_wavelengths(j) << " " << sample.channels.at(i).peak_powers(j) << " " << sample.channels.at(i).strains(j) << std::endl;
	//				}
	//				std::cout << std::endl;
	//			}
	//			
	//			for(int i = 0; i < sample.num_sensors; i++)
	//			{
	//				std::cout << sample.sensors.at(i).num_curv_points << std::endl << std::endl;
	//				std::cout << sample.sensors.at(i).curvature_strains << std::endl << std::endl;
	//				
	//			}
	//		}
	//	}
	//
	//
	//}
	
	
	return 1;
	
					
	
}

