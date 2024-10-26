Project :  Smart Home system
Requirements: 
1. Base Class: Appliance 
○ A generic appliance class that tracks brand, power usage, and on/off status with methods to turn the appliance on or off. 
2. Derived Classes: 
○ Class: WashingMachine (Inherits from Appliance): Adds the load capacity, power consumption per washing cycle attributes and provides functionality to start a wash cycle. 
○ Class: AirConditioner (Inherits from Appliance): Adds cooling capacity, average power consumption and methods to set the 
temperature. 
○ Class: Refrigerator (Inherits from Appliance): Adds storage volume, average power consumption and provides functionality to adjust internal temperature. 
3. Base Class: NetworkDevice 
○ A generic NetworkDevice class that tracks ipAddress (string) connectionStatus (boolean). It supports the following functions i. connect(string ipAddress) that connects the device to a network using the provided IP address. 
ii. disconnect(): Disconnects the device 
4. Multiple Inheritance: 
○ Class: SmartAppliance (Inherits from Appliance and 
NetworkDevice): Extends any appliance with network capabilities for remote control. 
5. Protected Inheritance: 
○ Class: NetworkDevice (Inherited as protected by 
SmartAppliance): Manages network connection attributes such as IP address and connection status. 
Tasks: 
1. Implement all the above classes with mentioned attributes and inheritance 2. Implement cumulative power tracking for both smart and non-smart appliances using static variable members. Create static variable members and any other variables required for you to track the cumulative power consumed by different products of each class.
CS-1004 Object Oriented Programming 
3. In Main, Use dynamic memory management to create and destroy objects of the different derived appliance classes including smart device class 
4. Implement method overriding for turnOn and turnOff where required. 5. Washing Machine when turned on does not start consuming power. It will consume power when watching cycles are started. 
6. Use appropriate access specifiers and demonstrate protected inheritance for network-related attributes. Even though, connect and disconnect functions of network device class are public, for smart appliances they should be protected. And these should be called automatically whenever a smart appliance is turned on or off. 
7. Demonstrate the use of all the features implemented in the main class 8. Ensure constructors initialize inherited and new attributes for each derived class. 9. For WashingMachine, power is only consumed during wash cycles. For the AirConditioner and Refrigerator, power is consumed while turned on.
