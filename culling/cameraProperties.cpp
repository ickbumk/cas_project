#include <opencv2/opencv.hpp>

cv::Mat getSampleIntrinsicMatrix() {
    double fx = 600.0;
    double fy = 600.0;
    double cx = 320.0;  // image width / 2
    double cy = 240.0;  // image height / 2

    cv::Mat K = (cv::Mat_<double>(3, 3) <<
        fx, 0,  cx,
        0,  fy, cy,
        0,  0,  1);
    
    return K;
}

cv::Mat getLookAtRT(const cv::Vec3d& eye, const cv::Vec3d& target, const cv::Vec3d& up) {
    // Compute forward (z), right (x), and true up (y)
    cv::Vec3d z = cv::normalize(eye - target);
    cv::Vec3d x = cv::normalize(up.cross(z));
    cv::Vec3d y = z.cross(x);

    // Create rotation matrix
    cv::Mat R = (cv::Mat_<double>(3, 3) <<
        x[0], x[1], x[2],
        y[0], y[1], y[2],
        z[0], z[1], z[2]);

    // Convert eye position to cv::Mat (3x1)
    cv::Mat eyeMat = (cv::Mat_<double>(3, 1) << eye[0], eye[1], eye[2]);

    // Compute translation t = -R * eye
    cv::Mat t = -R * eyeMat;  // Matrix multiplication, no dot product

    // Concatenate [R | t] to form 3x4 extrinsic matrix
    cv::Mat RT;
    cv::hconcat(R, t, RT);

    return RT;
}