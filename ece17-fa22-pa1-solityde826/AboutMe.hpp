//
//  Student.hpp
//  Student
//
//  Created by rick gessner on 3/23/22.
//

#ifndef AboutMe_hpp
#define AboutMe_hpp

#include <stdio.h>
#include <string>

namespace ECE17 {
  
  class AboutMe {
  public:
    AboutMe();
    AboutMe(const AboutMe &aStudent);
    AboutMe& operator=(const AboutMe &aStudent);
    ~AboutMe()=default;
    
    bool operator==(const AboutMe &aStudent) const;
    
    const std::string& getPID() const;
    const std::string& getName() const;

  protected:
    std::string name;
    std::string pid;
    size_t      years_at_ucsd;
  };

}

#endif /* about_me */
