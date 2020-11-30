// red.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<cstdlib>
#include<opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<string>
#include<vector>
#include<opencv2/features2d/features2d.hpp>
//#include<opencv2\xfeatures2d.hpp>

using namespace std;
using namespace cv;


vector<Mat> input(string path)
{
    string folder_path=path;
    vector<string> file_names;
    glob(folder_path, file_names);
    vector<Mat> img;
    Mat imgpass;
    for (int i = 0; i < file_names.size(); i++)
    {
        cout << file_names[i] << endl;
        imgpass=imread(file_names[i]);
        img.push_back(imgpass);
    }
    return img;
}

vector<vector<KeyPoint>> features(vector<Mat> inputimg)//特征点提取，使用FAST
{
	vector<KeyPoint> keypoint;
	vector<vector<KeyPoint>> keypoints;//keypoingts是keypoint的集合，指所有图像的特征点
	for (int i = 0; i < inputimg.size(); i++)
	{
		Ptr<FastFeatureDetector>  detector = FastFeatureDetector::create(40);
		detector->detect(inputimg[i], keypoint);
		keypoints.push_back(keypoint);
	}
	//在这里加入匹配，用FLANN?
	return keypoints;
}

vector<Mat> brief(vector<vector<KeyPoint>> keypoints, vector<Mat> imginput)//brief描述子计算，输入原图像和关键点
{
    BriefDescriptorExtractor brief;
    vector<Mat> descriptor;
    Mat descriptorpass;
    for (int i = 0; i < keypoints.size(); i++)
    {
        brief.compute(imginput[i], keypoints[i], descriptorpass);
        descriptor.push_back(descriptorpass);
    }
    return descriptor;//descriptor集成所有帧的描述子，单独帧可切片出来
}



int main()
{
    return 0;
}

