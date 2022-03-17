cmake_minimum_required(VERSION 3.20)
project(TestClasses)

set(CMAKE_CXX_STANDARD 17)

add_executable(TestClasses
        main.cpp
        TestFiles/test_Environment.h
        environment.h
        environment.cpp
        trajectory.h
        trajectory.cpp
#        TestFiles/test_Force.h
#        TestFiles/test_Mass.h
#        TestFiles/test_Acceleration.h
#        TestFiles/test_Howitzer.h
#        TestFiles/test_Seconds.h
        TestFiles/test_Trajectory.h
#        TestFiles/test_Velocity.h
        position.h
        position.cpp
        acceleration.h
        acceleration.cpp
        velocity.h
        velocity.cpp
        force.h
        force.cpp
        projectile.h
#        TestFiles/spies.h
        DefaultFiles/ground.h
        howitzer.h
#        mass.cpp
#        mass.h
        )
