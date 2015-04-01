CC = g++
CFLAGS = -L/usr/lib/nvidia-331 -lm -lGL -lGLU -lglut -std=c++11

all:
	$(CC) -o FavershamExpress main.cpp ./core/OpenGLManager.cpp ./core/Scene.cpp ./textures/loadBMP.cpp ./textures/loadRAW.cpp ./textures/loadTGA.cpp ./models/Barrier.cpp ./models/Carriage.cpp ./models/Humanoid.cpp ./models/Moon.cpp ./models/RailwaySignal.cpp ./models/SceneObject.cpp ./models/Skybox.cpp ./models/Stage.cpp ./models/Tower.cpp ./models/Train.cpp ./models/TrainStation.cpp ./models/track/InnerTrack.cpp ./models/track/OuterTrack.cpp ./models/track/TrainTracks.cpp $(CFLAGS)