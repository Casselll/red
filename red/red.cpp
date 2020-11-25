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

using namespace std;
using namespace cv;3


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

int main()
{
    return 0;
}

