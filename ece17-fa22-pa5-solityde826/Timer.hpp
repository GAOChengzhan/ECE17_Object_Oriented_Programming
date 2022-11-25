//
//  Timer.hpp
//

// Note: This timer could be "misused" -- think about how you might make it a bit more "foolproof"

#ifndef Timer_h
#define Timer_h

#include <chrono>

namespace ECE17 {
  class Timer {
  public:
    Timer() {
      stopped=started=std::chrono::high_resolution_clock::now();
    };

    Timer& start() {
      started=std::chrono::high_resolution_clock::now();
      return *this;
    }

    Timer& stop() {
      stopped=std::chrono::high_resolution_clock::now();
      return *this;
    }
    
    double elapsed() {
      if(started!=stopped) {
        std::chrono::duration<double> elapsed = stopped - started;
        return elapsed.count();
      }
      return 0.0;
    }
    
    std::chrono::time_point<std::chrono::high_resolution_clock> started;
    std::chrono::time_point<std::chrono::high_resolution_clock> stopped;
  };
}

#endif /* Timer_h */
