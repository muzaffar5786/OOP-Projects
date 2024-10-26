#include <iostream>
#include <string>
using namespace std;

class Appliance {
protected:
    string brand;
    static int cumulativePower; // Track cumulative power usage for all appliances

public:
    // Virtual functions to allow polymorphism for derived classes
    virtual void ON() {
        cout << "Appliance is ON now" << endl;
    }

    virtual void OFF() {
        cout << "Appliance is OFF now" << endl;
    }

    // Static function to display cumulative power usage
    static void powerDisplay() {
        cout << "The cumulative power consumed by all appliances is: " << cumulativePower << " watts" << endl;
    }

    virtual ~Appliance() {} // Virtual destructor for proper cleanup
};

// Initialize the static cumulativePower variable
int Appliance::cumulativePower = 0;

class WashingMachine : public Appliance {
    int loadCapacity;
    int powerPerCycle;

public:
    WashingMachine(int load, int powerCycle) : loadCapacity(load), powerPerCycle(powerCycle) {}

    void start(int cycles) {
        int powerUsed = powerPerCycle * cycles;
        cumulativePower += powerUsed;
        cout << "Washing machine completed " << cycles << " cycles." << endl;
        cout << "Power consumed by washing machine: " << powerUsed << " watts" << endl;
    }
};

class AirConditioner : public Appliance {
    int coolingCapacity;
    int avgPowerConsumption;

public:
    AirConditioner(int coolingCap, int avgPower) : coolingCapacity(coolingCap), avgPowerConsumption(avgPower) {}

    void setTemperature(int temp) {
        cumulativePower += avgPowerConsumption;
        cout << "Air conditioner temperature set to " << temp << " degrees." << endl;
        cout << "Power consumed by air conditioner: " << avgPowerConsumption << " watts" << endl;
    }
};

class Refrigerator : public Appliance {
    int storageVolume;
    int avgPowerConsumption;

public:
    Refrigerator(int volume, int avgPower) : storageVolume(volume), avgPowerConsumption(avgPower) {}

    void adjustTemperature(int temp) {
        cumulativePower += avgPowerConsumption;
        cout << "Refrigerator temperature set to " << temp << " degrees." << endl;
        cout << "Power consumed by refrigerator: " << avgPowerConsumption << " watts" << endl;
    }
};

// NetworkDevice base class
class NetworkDevice {
protected:
    string ipAddress;
    bool connectionStatus;

public:
    NetworkDevice() : connectionStatus(false) {}

    void connect(const string& ip) {
        ipAddress = ip;
        connectionStatus = true;
        cout << "Connected to network with IP: " << ipAddress << endl;
    }

    void disconnect() {
        connectionStatus = false;
        cout << "Disconnected from network." << endl;
    }
};

// SmartAppliance class with protected inheritance from NetworkDevice
class SmartAppliance : public Appliance, protected NetworkDevice {
public:
    SmartAppliance() {}

    // Override ON and OFF to include connect and disconnect automatically
    void ON() override {
        connect("192.168.1.100"); // Automatically connect when turned on
        cout << "Smart appliance is ON with network capabilities." << endl;
    }

    void OFF() override {
        disconnect(); // Automatically disconnect when turned off
        cout << "Smart appliance is OFF." << endl;
    }

    void remoteControl() {
        cout << "Controlling the appliance remotely." << endl;
    }
};

int main() {
    // Dynamically allocate appliances using dynamic memory management

    // Washing machine example
    Appliance* wm = new WashingMachine(7, 350); // 7 kg load, 350 watts per cycle
    wm->ON();
    dynamic_cast<WashingMachine*>(wm)->start(3); // Runs 3 cycles
    wm->OFF();
    delete wm; // Clean up memory

    // Air conditioner example
    Appliance* ac = new AirConditioner(18000, 800); // 18000 BTU, 800 watts average
    ac->ON();
    dynamic_cast<AirConditioner*>(ac)->setTemperature(22);
    ac->OFF();
    delete ac;

    // Refrigerator example
    Appliance* fridge = new Refrigerator(300, 100); // 300 liters, 100 watts average
    fridge->ON();
    dynamic_cast<Refrigerator*>(fridge)->adjustTemperature(4);
    fridge->OFF();
    delete fridge;

    // SmartAppliance example
    SmartAppliance* smartAppliance = new SmartAppliance();
    smartAppliance->ON();  // Connects automatically
    smartAppliance->remoteControl();
    smartAppliance->OFF(); // Disconnects automatically
    delete smartAppliance;

    // Display cumulative power usage
    Appliance::powerDisplay();

    return 0;
}
