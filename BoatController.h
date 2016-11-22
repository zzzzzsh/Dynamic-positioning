#ifndef _BOATCONTROLLER_H_
#define _BOATCONTROLLER_H_

#include "PhysicalDefinitions.h"
#include <thread>
#include <chrono>

class BoatController{
	public:
        BoatController(Boat *b);
        ~BoatController();

        //Start stop control thread
        void startControl();
        void stopControl();

        bool isRunning() {return running;};

	private:
        Boat *boat;
        std::thread controlThread;
        std::chrono::duration<float> periodTime;
        std::chrono::time_point<std::chrono::high_resolution_clock> lastTime, currentTime;

        bool running = false;

        //Controllers
        PIDController *xController;
		PIDController *yController;
		PIDController *hController;

        void controlFunction();
		float calculateHeading(Vector2<float> currentPosition, Vector2<float> setpointPosition);
};
#endif
