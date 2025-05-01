# Occlusion Culling

## Instruction 
Clone this repo

```bash
git clone https://github.com/ickbumk/cas_project.git
```

You can compile using autoconfig.

```bash
cd cas_project
./autoconfig.sh
```

If autoconfig does not execute try by changing the shell to executable:

```bash
cd cas_project
chmod +x autoconfig.sh
./autoconfig.sh
```

It should download Catch2 and OpenCV, if it is not installed. The compilation will be done automatically. 

Once it is complete, navigate to build directory to run the main executable.

```bash
cd build
./main
```


## Using your own camera properties and dataset

To change the dataset, navigate to main.cpp and change the directory.

```bash
std::string filename = "../dataset/path/to/your/obj"
```

To change the camera extrinsic properties, change eye, target, up
```bash
cv::Vec3d eye(your, camera, position)
cv::Vec3d target(your, camera, lookat)
cv::Vec3d up(your, coordinate, orientation)
```

Eye determines the camera position, target calculates the direction your camera is pointing to, and up determines your coordinate orientation; (0,1,0) means y direction is upwards.

To change the camera intrinsic properties, navigate to cas_project/culling/cameraProperties.cpp, and change cv::Mat getSampleIntrinsicMatrix()

```bash
double fx = your_focalx
double fy = your_focaly
double cx = your_principalx
double cy = your_principaly
```

