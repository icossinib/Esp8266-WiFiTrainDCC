# Esp8266-WiFiTrainDCC
This repository host a project for controlling Model trains through WiFi using Esp8266.
The goal of the project is to migrate a full analogic Train model system to a DCC model system controlled via WiFi.

Given a train model layout, the elements that can be found are:
- Control Panel
- Trains
- Wagons
- Railways
- Decorational devices.

## Control Panel
The control panel is the center node of the network. It gathers the input from the user (from different input devices) and sends it to the devices connected to the network.

## Trains
The trains are the locomotives that can run over the railways. Currently we use DC locomotives controlled by Analogic transformers sending different Voltages through the railways. 

## Wagons
The wagons are devices attached to other wagons or locomotives. They don't have their own motion, just follow the locomotive. They can have lights or any other decorative electronic system.

## Railways
The railways are the device that supports the electric line, guide the trains and defines the layout. In this case we will use 2 ways railways.

## Train track control device
The train track control devices are switchs (electrical or not), bridges, rounds, and any other device that can alter the way that a train will follow. 

## Decorational devices
The decorational devices are all the other devices that can be used in the layout for decorative purposes. House lights, trac illumination, moving cars... etc.

# Software Part

The project consists in two main parts:
- Device application (client)
- Control application (server)

The device application are the software and hardwdare installed in any Train, Wagon, or other device different than Control device. This holds the electric layout and the software used in this project.

The Control Application are the software and hardware used by the control device to gather user input and signal distribution to the trains and other devices. 


this readme file can be updated and extended.
