# coding: UTF-8
# Sample script for reading a single port using Receiver class.
#Author - Yatharth Bhasin (github → yatharthb97)

from receiver import Receiver, ListPorts
from acquisition_fns import Events_Acq, Time_Acq
from receive_handlers import *

#List All Ports
#ListPorts()

#Initalise ports
ports_x = [Receiver("Teensy Output", "COM8", Baudrate = 115200, Sep = ',')]
#ports = Receiver("Teensy Output", "COM8", Baudrate = 115200, Sep = ',')


ports_x = Events_Acq("Test1", ports_x, receive_with_time_print, 1000)