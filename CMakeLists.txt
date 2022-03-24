cmake_minimum_required(VERSION 3.20)
project(TestClasses)

set(CMAKE_CXX_STANDARD 17)

add_executable(TestClasses
        SourceFiles/main.cpp
        TestFiles/test_Environment.h
        HeaderFiles/environment.h
        SourceFiles/environment.cpp
        HeaderFiles/trajectory.h
        SourceFiles/trajectory.cpp
#        TestFiles/test_Force.h
#        TestFiles/test_Mass.h
#        TestFiles/test_Acceleration.h
#        TestFiles/test_Howitzer.h
#        TestFiles/test_Seconds.h
        TestFiles/test_Trajectory.h
#        TestFiles/test_Velocity.h
        HeaderFiles/position.h
        SourceFiles/position.cpp
        HeaderFiles/projectile.h
        DefaultFiles/ground.h
        HeaderFiles/howitzer.h

        HeaderFiles/seconds.h
        SourceFiles/seconds.cpp
        SourceFiles/mass.cpp
        HeaderFiles/mass.h
        HeaderFiles/acceleration.h
        SourceFiles/acceleration.cpp
        HeaderFiles/velocity.h
        SourceFiles/velocity.cpp
        HeaderFiles/force.h
        SourceFiles/force.cpp
        SourceFiles/simulator.cpp
        HeaderFiles/simulator.h
        SourceFiles/userInput.cpp
        HeaderFiles/userInput.h
        SourceFiles/howitzer.cpp)
#        SourceFiles/howitzer.cpp
#        SourceFiles/simulator.cpp
#        HeaderFiles/simulator.h
