#include <fnr_slam/FNRSLAM.h>

FNRSLAM::FNRSLAM(time_t max_node_age) {
	this->graph = std::make_shared<Graph>(max_node_age);
}

FNRSLAM::~FNRSLAM() {
}

void FNRSLAM::setCameraTf(std::string frame_id, Eigen::Affine3d tf) {
	if(this->streams[frame_id] == nullptr)
		this->streams[frame_id] = std::make_shared<VideoStream>();
	this->streams[frame_id]->setTfToBase(tf);
}

void FNRSLAM::setCameraIntrinsics(std::string frame_id, Eigen::Matrix3d K) {
	if(this->streams[frame_id] == nullptr)
		this->streams[frame_id] = std::make_shared<VideoStream>();
	this->streams[frame_id]->setIntrinsics(K);
}

void FNRSLAM::feedDepthImage(std::string frame_id, cv::Mat image) {
	if(this->streams[frame_id] == nullptr)
		this->streams[frame_id] = std::make_shared<VideoStream>();
	this->streams[frame_id]->addDepthImage(image);
}

void FNRSLAM::feedColorImage(std::string frame_id, cv::Mat image) {
	if(this->streams[frame_id] == nullptr)
		this->streams[frame_id] = std::make_shared<VideoStream>();
	this->streams[frame_id]->addColorImage(image);
}
