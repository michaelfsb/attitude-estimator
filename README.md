# Attitude Estimator

This code estimates the angles roll and pitch using an accelerometer dataset. A file with a generic name is read, and a file with the name attitude_result.log is generated, as shown in this diagram. 

```mermaid
  graph LR;
      input_file-->AttitudeEstimator;
      AttitudeEstimator-->attitude_result.log;
```

The input file name, <input file>, is a parameter that must be passed when calling the main function. This file must be follow the pattern: <time_stamp_ms; accel_x_axis; accel_y_axis; accel_z_axis>. 

The output file is generated in the same path that complied code, and this file follows the pattern: <time_stamp_ms; roll; pitch>. The unit of this angle is degree.

To build and execute the project, run

    $ mkdir build
    $ cd build
    $ cmake ..
    $ make
    $ ./AttitudeEstimator <input file>

## Estimation calculation

The estimation calculation of pitch $\theta_{xyz}$ and roll $\phi_{xyz}$ is done from the following equations:

$$
\theta_{xyz}=\tan^{-1}{\frac{-G_{px}}{\sqrt{G_{py}^2 + G_{pz}^2}}},
$$

$$
\phi_{xyz}=\tan^{-1}{\frac{G_{py}}{G_{pz}}},
$$

whrer $G_{px}$ is the acceleration in the $x$ axis, $G_{py}$ is the acceleration in the $y$ axis, and $G_{pz}$ is the acceleration in the $z$ axis.
To obtain the angle in the correct quadrant, the function ATAN2 was used.
