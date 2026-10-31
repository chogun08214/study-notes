#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

#include <opencv2/opencv.hpp>
#define _CRT_SECURE_NO_WARNINGS

using namespace cv;

int ex0903(void)
{
	Mat img = imread("google.png");

	imshow("test", img);
	waitKey(5000);

	return 0;
}

typedef struct {
	int r, g, b;
}int_rgb;


int** IntAlloc2(int height, int width)
{
	int** tmp;
	tmp = (int**)calloc(height, sizeof(int*));
	for (int i = 0; i < height; i++)
		tmp[i] = (int*)calloc(width, sizeof(int));
	return(tmp);
}

void IntFree2(int** image, int height, int width)
{
	for (int i = 0; i < height; i++)
		free(image[i]);

	free(image);
}


float** FloatAlloc2(int height, int width)
{
	float** tmp;
	tmp = (float**)calloc(height, sizeof(float*));
	for (int i = 0; i < height; i++)
		tmp[i] = (float*)calloc(width, sizeof(float));
	return(tmp);
}

void FloatFree2(float** image, int height, int width)
{
	for (int i = 0; i < height; i++)
		free(image[i]);

	free(image);
}

int_rgb** IntColorAlloc2(int height, int width)
{
	int_rgb** tmp;
	tmp = (int_rgb**)calloc(height, sizeof(int_rgb*));
	for (int i = 0; i < height; i++)
		tmp[i] = (int_rgb*)calloc(width, sizeof(int_rgb));
	return(tmp);
}

void IntColorFree2(int_rgb** image, int height, int width)
{
	for (int i = 0; i < height; i++)
		free(image[i]);

	free(image);
}

int** ReadImage(char* name, int* height, int* width)
{
	Mat img = imread(name, IMREAD_GRAYSCALE);
	int** image = (int**)IntAlloc2(img.rows, img.cols);

	*width = img.cols;
	*height = img.rows;

	for (int i = 0; i < img.rows; i++)
		for (int j = 0; j < img.cols; j++)
			image[i][j] = img.at<unsigned char>(i, j);

	return(image);
}

void WriteImage(char* name, int** image, int height, int width)
{
	Mat img(height, width, CV_8UC1);
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			img.at<unsigned char>(i, j) = (unsigned char)image[i][j];

	imwrite(name, img);
}


void ImageShow(char* winname, int** image, int height, int width)
{
	Mat img(height, width, CV_8UC1);
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			img.at<unsigned char>(i, j) = (unsigned char)image[i][j];
	imshow(winname, img);
	waitKey(0);
}



int_rgb** ReadColorImage(char* name, int* height, int* width)
{
	Mat img = imread(name, IMREAD_COLOR);
	int_rgb** image = (int_rgb**)IntColorAlloc2(img.rows, img.cols);

	*width = img.cols;
	*height = img.rows;

	for (int i = 0; i < img.rows; i++)
		for (int j = 0; j < img.cols; j++) {
			image[i][j].b = img.at<Vec3b>(i, j)[0];
			image[i][j].g = img.at<Vec3b>(i, j)[1];
			image[i][j].r = img.at<Vec3b>(i, j)[2];
		}

	return(image);
}

void WriteColorImage(char* name, int_rgb** image, int height, int width)
{
	Mat img(height, width, CV_8UC3);
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) {
			img.at<Vec3b>(i, j)[0] = (unsigned char)image[i][j].b;
			img.at<Vec3b>(i, j)[1] = (unsigned char)image[i][j].g;
			img.at<Vec3b>(i, j)[2] = (unsigned char)image[i][j].r;
		}

	imwrite(name, img);
}

void ColorImageShow(char* winname, int_rgb** image, int height, int width)
{
	Mat img(height, width, CV_8UC3);
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) {
			img.at<Vec3b>(i, j)[0] = (unsigned char)image[i][j].b;
			img.at<Vec3b>(i, j)[1] = (unsigned char)image[i][j].g;
			img.at<Vec3b>(i, j)[2] = (unsigned char)image[i][j].r;
		}
	imshow(winname, img);

}

template <typename _TP>
void ConnectedComponentLabeling(_TP** seg, int height, int width, int** label, int* no_label)
{

	//Mat bw = threshval < 128 ? (img < threshval) : (img > threshval);
	Mat bw(height, width, CV_8U);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			bw.at<unsigned char>(i, j) = (unsigned char)seg[i][j];
	}
	Mat labelImage(bw.size(), CV_32S);
	*no_label = connectedComponents(bw, labelImage, 8); // 0        Ե        

	(*no_label)--;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			label[i][j] = labelImage.at<int>(i, j);
	}
}

#define imax(x, y) ((x)>(y) ? x : y)
#define imin(x, y) ((x)<(y) ? x : y)

int BilinearInterpolation(int** image, int width, int height, double x, double y)
{
	int x_int = (int)x;
	int y_int = (int)y;

	int A = image[imin(imax(y_int, 0), height - 1)][imin(imax(x_int, 0), width - 1)];
	int B = image[imin(imax(y_int, 0), height - 1)][imin(imax(x_int + 1, 0), width - 1)];
	int C = image[imin(imax(y_int + 1, 0), height - 1)][imin(imax(x_int, 0), width - 1)];
	int D = image[imin(imax(y_int + 1, 0), height - 1)][imin(imax(x_int + 1, 0), width - 1)];

	double dx = x - x_int;
	double dy = y - y_int;

	double value
		= (1.0 - dx) * (1.0 - dy) * A + dx * (1.0 - dy) * B
		+ (1.0 - dx) * dy * C + dx * dy * D;

	return((int)(value + 0.5));
}


void DrawHistogram(char* comments, int* Hist)
{
	int histSize = 256; /// Establish the number of bins
	// Draw the histograms for B, G and R
	int hist_w = 512; int hist_h = 512;
	int bin_w = cvRound((double)hist_w / histSize);

	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));
	Mat r_hist(histSize, 1, CV_32FC1);
	for (int i = 0; i < histSize; i++)
		r_hist.at<float>(i, 0) = Hist[i];
	/// Normalize the result to [ 0, histImage.rows ]
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	/// Draw for each channel
	for (int i = 1; i < histSize; i++)
	{
		line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
			Point(bin_w * (i), hist_h - cvRound(r_hist.at<float>(i))),
			Scalar(255, 0, 0), 2, 8, 0);
	}

	/// Display
	namedWindow(comments, WINDOW_AUTOSIZE);
	imshow(comments, histImage);

	waitKey(0);

}





int ex0911_1(void) //십자모양 만들기 
{
	int height = 512, width = 1024;
	int** img = (int**)IntAlloc2(height, width);

	int y = 256;
	int x = 512;

	for (int i = 0; i < 1024; i++)
	{
		img[y][i] = 255;
	}

	for (int j = 0; j < 512; j++)
	{
		img[j][x] = 255;
	}

	ImageShow((char*)"output", img, height, width);

	IntFree2(img, height, width);

	return 0;
}

int ex0911_2(void)
{
	int height = 512, width = 1024;
	int** img = (int**)IntAlloc2(height, width);

	int y, x;

	for (int i = 150; i < 406; i++)
	{
		for (x = 300; x < 812; x++)
		{
			img[i][x] = 255;
		}
	}

	

	ImageShow((char*)"output", img, height, width);

	IntFree2(img, height, width);

	return 0;
}



void drawLine(int** img, int y, int x0, int x1)
{
	for (int x = x0; x < x1; x++)
	{
		img[y][x] = 255;
	}
}

int ex0911_3(void)
{
	int height = 512, width = 1024;
	int** img = (int**)IntAlloc2(height, width);

	int x0 = width/4, x1 = width*3/4;

	for (int y = 150; y < 406; y++)
	{
		drawLine(img, y, x0, x1);
	}

	WriteImage((char*)"test.jpg", img, height, width);
	ImageShow((char*)"output", img, height, width);

	IntFree2(img, height, width);

	return 0;
}

void Thresholding(int threshold, int** img, int height, int width, int** img_out)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (img[y][x] > threshold)
			{
				img_out[y][x] = 255;
			}
			else
			{
				img_out[y][x] = 0;
			}
		}
	}
}

int ex0924_1(void)
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);
	int** img_out = (int**)IntAlloc2(height, width);
	int threshold = 200;

	ImageShow((char*)"input", img, height, width);

	for(threshold = 50; threshold < 250; threshold += 50)
	{
		Thresholding(threshold, img, height, width, img_out);
		ImageShow((char*)"output", img_out, height, width);
	}

	return 0;
}

void ShiftImage(int value, int** img, int height, int width)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			img[y][x] = img[y][x] + value;
		}
	}
}

#define GetMax(x, y) ((x > y) ? x : y)
#define GetMin(x, y) ((x < y) ? x : y)

void ClippingImage(int** img, int height, int width, int** img_out)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			/*
			if (img[y][x] > 255)
			{
				img_out[y][x] = 255;
			}
			else if (img[y][x] < 0)
			{
				img_out[y][x] = 0;
			}
			else
			{
				img_out[y][x] = img[y][x];
			}
			*/
			//int A = GetMax(img[y][x], 0);
			//int B = GetMin(A, 255);
			//img_out[y][x] = B;

			img_out[y][x] = GetMin(GetMax(img[y][x], 0), 255);
		}
	}
}

int ex0924_2(void)
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);
	int** img_out = (int**)IntAlloc2(height, width);

	ShiftImage(50, img, height, width);

	ClippingImage(img, height, width, img_out);

	ImageShow((char*)"input", img, height, width);
	ImageShow((char*)"output", img_out, height, width);

	return 0;
}

#define NUM 300

int ex0924_3(void)
{
	int aaa = -10, bbb = NUM;
	int A, B;

	A = GetMax(aaa, 0); // A - ((aaa > 0) ? aaa : 0)
	B = GetMin(A, 255); // B = ((bbb < 255) ? bbb : 255)

	return 0;
}

/********************************************************************/

int ex0925_1(void)
{
	int A = 100, B = 200, C = 300;
	//int D = GetMax(A, B);
	int E = GetMax(GetMax(A, B), C);

	return 0;
}

int FindMaxValue(int** img, int height, int width)
{
	int max_value = img[0][0];

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			max_value = GetMax(max_value, img[y][x]);
		}
	}

	return max_value;
}

int FindMinValue(int** img, int height, int width)
{
	int min_value = img[0][0];

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			min_value = GetMin(min_value, img[y][x]);
		}
	}

	return min_value;
}

int ex0925_2(void)
{
	int A[7] = { 1, -1, 3, 8, 2, 9, 10 };
	int max_value = A[0];
	int min_value = A[0];

	for (int n = 1; n < 7; n++)
	{
		max_value = GetMax(max_value, A[n]);
	}

	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);

	max_value = FindMaxValue(img, height, width);
	min_value = FindMinValue(img, height, width);

	return 0;
}

void MixingImages(float alpha, int** img1, int** img2, int height, int width, int** img_out)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			img_out[y][x] = alpha * img1[y][x] + (1.0 - alpha) * img2[y][x];
		}
	}
}

void ex0925_3()
{
	int height, width;
	int** img1 = ReadImage((char*)"./TestImages/lena.png", &height, &width);
	int** img2 = ReadImage((char*)"./TestImages/barbara.png", &height, &width);
	int** img_out = (int**)IntAlloc2(height, width);
	
	for (float alpha = 0.0; alpha < 1.0; alpha+=0.1)
	{
		MixingImages(alpha, img1, img2, height, width, img_out);
		ImageShow((char*)"output", img_out, height, width);
	}
}

void ex_roundup()
{
	float a = 100.4;
	int b = a + 0.5;
}

void Stretch1(int** img, int height, int width, int a, int** img_out)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (img[y][x] < a)
			{
				img_out[y][x] = (int)((255.0 / a) * img[y][x] + 0.5);
			}
			else
			{
				img_out[y][x] = 255;
			}
		}
	}
}

void Stretch2(int** img, int height, int width, int a, int b, int c, int d, int** img_out)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (img[y][x] < a)
			{
				img_out[y][x] = ((float)c / a) * img[y][x] + 0.5;
			}
			else if (img[y][x] < b)
			{
				img_out[y][x] = ((((float)d - c) / (b - a)) * (img[y][x] - a)) + c + 0.5;
			}
			else
			{
				img_out[y][x] = (((255.0 - d) / (255 - b)) * (img[y][x] - b)) + d + 0.5;
			}
		}
	}
}

struct Parameter {

	int a;
	int b;
	int c;
	int d;
};

void Stretch3(int** img, int height, int width, Parameter param, int** img_out)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (img[y][x] < param.a)
			{
				img_out[y][x] = ((float)param.c / param.a) * img[y][x] + 0.5;
			}
			else if (img[y][x] < param.b)
			{
				img_out[y][x] = ((((float)param.d - param.c) / (param.b - param.a)) * (img[y][x] - param.a)) + param.c + 0.5;
			}
			else
			{
				img_out[y][x] = (((255.0 - param.d) / (255 - param.b)) * (img[y][x] - param.b)) + param.d + 0.5;
			}
		}
	}
}

struct ParameterAll {
	int** img;
	int height;
	int width;
	int a, b, c, d; 
	int** img_out;
};

void Stretch4(ParameterAll p)
{
	for (int y = 0; y < p.height; y++)
	{
		for (int x = 0; x < p.width; x++)
		{
			if (p.img[y][x] < p.a)
			{
				p.img_out[y][x] = ((float)p.c / p.a) * p.img[y][x] + 0.5;
			}
			else if (p.img[y][x] < p.b)
			{
				p.img_out[y][x] = ((((float)p.d - p.c) / (p.b - p.a)) * (p.img[y][x] - p.a)) + p.c + 0.5;
			}
			else
			{
				p.img_out[y][x] = (((255.0 - p.d) / (255 - p.b)) * (p.img[y][x] - p.b)) + p.d + 0.5;
			}
		}
	}
}

void ex0925_4()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);
	int** img_out = (int**)IntAlloc2(height, width);

	//int a = 100, b = 200, c = 25, d = 250;

	//Stretch1(img, height, width, a, img_out);
	//Stretch2(img, height, width, a, b, c, d, img_out);

	//Parameter param;
	//param.a = 100;
	//param.b = 150;
	//param.c = 50;
	//param.d = 200;

	//Stretch3(img, height, width, param, img_out);

	ParameterAll param;
	param.a = 100;
	param.b = 150;
	param.c = 50;
	param.d = 200;
	param.img = img;
	param.height = height;
	param.width = width;
	param.img_out = img_out;
	Stretch4(param);;


	ImageShow((char*)"input", img, height, width);
	ImageShow((char*)"output", img_out, height, width);
}

int GetCount(int value, int** img, int height, int width)
{
	int count = 0;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (img[y][x] == value)
			{
				count++;
			}
		}
	}

	return count;
}

void GetHistogram(int** img, int height, int width, int* histogram)
{
	for (int value = 0; value < 256; value++)
	{
		histogram[value] = GetCount(value, img, height, width);
	}
}

void ex1008_1()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);

	int histogram[256];
	GetHistogram(img, height, width, histogram);

	DrawHistogram((char*)"histo", histogram);
	//ImageShow((char*)"input", img, height, width);

}

void GetHistogram2(int** img, int height, int width, int* histogram)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			histogram[img[y][x]]++;
		}
	}
}

void GetChistogram(int** img, int height, int width, int* chist)
{

	int histogram[256] = { 0 };

	GetHistogram2(img, height, width, histogram);

	chist[0] = histogram[0];
	for (int n = 0; n < 256; n++)
	{
		chist[n] = chist[n - 1] + histogram[n];
	}
}

void ex1008_2()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);

	int chist[256] = { 0 };
	GetChistogram(img, height, width, chist);

	DrawHistogram((char*)"chisto", chist);

}

void HistEQ(int** img, int**img_out, int height, int width)
{

	int chist[256] = { 0 };
	GetChistogram(img, height, width, chist);

	int norm_chist[256] = { 0 };

	for (int n = 0; n < 256; n++)
	{
		norm_chist[n] = (float)chist[n] / (width * height) * 255 + 0.5;
	}

	//mapping using 'norm_chist[]
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			img_out[y][x] = norm_chist[img[y][x]];
		}
	}
}

void mainex1008_3()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lenax0.5.png", &height, &width);
	int** img_out = (int**)IntAlloc2(height, width);

	HistEQ(img, img_out, height, width);

	ImageShow((char*)"input", img, height, width);
	ImageShow((char*)"output", img_out, height, width);

	int hist_input[256] = { 0 };
	int hist_output[256] = { 0 };
	GetHistogram2(img, height, width, hist_input);
	GetHistogram2(img_out, height, width, hist_output);
	DrawHistogram((char*)"input_hist", hist_input);
	DrawHistogram((char*)"output_hist", hist_output);

}

int getMean3x3(int** img, int y, int x)
{
	int sum = 0;

	for (int m = -1; m <= 1; m++)
	{
		for (int n = -1; n <= 1; n++)
		{
			sum += img[y + m][x + n];
		}
	}

	return (int)(sum / 9.0 + 0.5);
}

void meanFilter3x3(int**img, int height, int width, int** img_out)
{
	int x, y;
	for (y = 1; y < height - 1; y++)
	{
		for (x = 1; x < width - 1; x++)
		{
			img_out[y][x] = getMean3x3(img, y, x);
		}
	}

	y = 0;
	for (x = 0; x < width; x++)
	{
		img_out[y][x] = img[y][x];
	}

	y = height - 1;
	for (x = 0; x < width; x++)
	{
		img_out[y][x] = img[y][x];
	}

	x = 0;
	for (y = 0; y < height; y++)
	{
		img_out[y][x] = img[y][x];
	}

	y = width - 1;
	for (y = 0; y < height; y++)
	{
		img_out[y][x] = img[y][x];
	}
}

int getMean5x5(int** img, int y, int x)
{
	int sum = 0;

	for (int m = -2; m <= 2; m++)
	{
		for (int n = -2; n <= 2; n++)
		{
			sum += img[y + m][x + n];
		}
	}

	return (int)(sum / 25.0 + 0.5);
}

void meanFilter5x5(int** img, int height, int width, int** img_out)
{
	int x, y;
	for (y = 2; y < height - 2; y++)
	{
		for (x = 2; x < width - 2; x++)
		{
			img_out[y][x] = getMean5x5(img, y, x);
		}
	}

	for (y = 0; y <= 1; y++)
	{
		for (x = 0; x < width; x++)
		{
			img_out[y][x] = img[y][x];
		}
	}
	
	for (y = height - 2; y < height; y++)
	{
		for (x = 0; x < width; x++)
		{
			img_out[y][x] = img[y][x];
		}
	}

	for (x = 0; x <= 1; x++)
	{
		for (y = 0; y < height; y++)
		{
			img_out[y][x] = img[y][x];
		}
	}

	for (y = width - 2; y < width; y++)
	{
		for (y = 0; y < height; y++)
		{
			img_out[y][x] = img[y][x];
		}
	}
}

int getMean7x7(int** img, int y, int x)
{
	int sum = 0;

	for (int m = -3; m <= 3; m++)
	{
		for (int n = -3; n <= 3; n++)
		{
			sum += img[y + m][x + n];
		}
	}

	return (int)(sum / 49.0 + 0.5);
}

void meanFilter7x7(int** img, int height, int width, int** img_out)
{
	int x, y;
	for (y = 3; y < height - 3; y++)
	{
		for (x = 3; x < width - 3; x++)
		{
			img_out[y][x] = getMean7x7(img, y, x);
		}
	}

	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < width; x++)
		{
			img_out[y][x] = img[y][x];
		}
	}

	for (y = height - 3; y < height; y++)
	{
		for (x = 0; x < width; x++)
		{
			img_out[y][x] = img[y][x];
		}
	}

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < height; y++)
		{
			img_out[y][x] = img[y][x];
		}
	}

	for (y = width - 3; y < width; y++)
	{
		for (y = 0; y < height; y++)
		{
			img_out[y][x] = img[y][x];
		}
	}
}

void ex1016_1()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);
	int** img_out3x3 = (int**)IntAlloc2(height, width);
	int** img_out5x5 = (int**)IntAlloc2(height, width);
	int** img_out7x7 = (int**)IntAlloc2(height, width);

	meanFilter3x3(img, height, width, img_out3x3);
	meanFilter5x5(img, height, width, img_out5x5);
	meanFilter7x7(img, height, width, img_out7x7);

	ImageShow((char*)"input", img, height, width);
	ImageShow((char*)"output3x3", img_out3x3, height, width);
	ImageShow((char*)"output5x5", img_out5x5, height, width);
	ImageShow((char*)"output7x7", img_out7x7, height, width);
}

int getMeanNxN(int N, int** img, int x, int y)
{
	int delta = (N - 1) / 2;
	int sum = 0;

	for (int m = -delta; m <= delta; m++)
	{
		for (int n = -delta; n <= delta; n++)
		{
			sum += img[y + m][x + n];
		}
	}

	return (int)(sum / ((float)N * N) + 0.5);
}

void meanFilterNxN(int N, int** img, int height, int width, int** img_out)
{
	int delta = (N - 1) / 2;

	int x, y;
	for (y = delta; y < height - delta; y++)
	{
		for (x = delta; x < width - delta; x++)
		{
			img_out[y][x] = getMeanNxN(N, img, x, y);
		}
	}

	for (y = 0; y < delta; y++)
	{
		for (x = 0; x < width; x++)
		{
			img_out[y][x] = img[y][x];
		}
	}

	for (y = height - delta; y < height; y++)
	{
		for (x = 0; x < width; x++)
		{
			img_out[y][x] = img[y][x];
		}
	}

	for (x = 0; x < delta; x++)
	{
		for (y = 0; y < height; y++)
		{
			img_out[y][x] = img[y][x];
		}
	}

	for (y = width - delta; y < width; y++)
	{
		for (y = 0; y < height; y++)
		{
			img_out[y][x] = img[y][x];
		}
	}
}

void ex1016_2()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);
	int** img_out = (int**)IntAlloc2(height, width);

	ImageShow((char*)"input", img, height, width);
	for (int N = 3; N < 15; N += 2)
	{
		meanFilterNxN(N, img, height, width, img_out);
		ImageShow((char*)"output", img_out, height, width); 
	}

}

int MaskingOne(int y, int x, float** kernel, int** img)
{
	float sum = 0.0;

	for (int m = -1; m <= 1; m++)
	{
		for (int n = -1; n <= 1; n++)
		{
			sum += img[y + m][x + n] * kernel[m + 1][n + 1];
		}
	}

	return (int)(sum + 0.5);
}

void MaskingImage(float** kernel, int** img, int height, int width, int** img_out)
{
	for (int y = 1; y < height - 1; y++)
	{
		for (int x = 1; x < width - 1; x++)
		{
			img_out[y][x] = MaskingOne(y, x, kernel, img);
		}
	}
}

void ex1030_1()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);
	int** img_out = (int**)IntAlloc2(height, width);
	float** kernel = (float**)FloatAlloc2(3, 3);

	kernel[0][0] = 1 / 9.0;
	kernel[0][1] = 1 / 9.0;
	kernel[0][2] = 1 / 9.0;
	kernel[1][0] = 1 / 9.0;
	kernel[1][1] = 1 / 9.0;
	kernel[1][2] = 1 / 9.0;
	kernel[2][0] = 1 / 9.0;
	kernel[2][1] = 1 / 9.0;
	kernel[2][2] = 1 / 9.0;

	MaskingImage(kernel, img, height, width, img_out);

	ImageShow((char*)"input", img, height, width);
	ImageShow((char*)"output", img_out, height, width);
}

void ex1030_2()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);
	int** img_out = (int**)IntAlloc2(height, width);
	float** kernel = (float**)FloatAlloc2(3, 3);

	kernel[0][0] = -1.0;
	kernel[0][1] = -1.0;
	kernel[0][2] = -1.0;
	kernel[1][0] = -1.0;
	kernel[1][1] = 8.0;
	kernel[1][2] = -1.0;
	kernel[2][0] = -1.0;
	kernel[2][1] = -1.0;
	kernel[2][2] = -1.0;

	MaskingImage(kernel, img, height, width, img_out);
	ClippingImage(img_out, height, width, img_out);

	ImageShow((char*)"input", img, height, width);
	ImageShow((char*)"output", img_out, height, width);
}

void MagGradient_x(int** img, int** img_out, int height, int width)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width - 1; x++)
		{
			img_out[y][x] = abs(img[y][x + 1] - img[y][x]);
		}
	}
}

void MagGradient_y(int** img, int** img_out, int height, int width)
{
	for (int y = 0; y < height - 1; y++)
	{
		for (int x = 0; x < width; x++)
		{
			img_out[y][x] = abs(img[y + 1][x] - img[y][x]);
		}
	}
}

void ScalingImage(float scale, int** img_in_out, int height, int width)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			img_in_out[y][x] = scale * img_in_out[y][x];
			if (img_in_out[y][x] > 255)
			{
				img_in_out[y][x] = 255;
			}
		}
	}
}

void ex1029_1()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/barbara.png", &height, &width);
	int** img_out_x = (int**)IntAlloc2(height, width);
	int** img_out_y = (int**)IntAlloc2(height, width);

	MagGradient_x(img, img_out_x, height, width);
	MagGradient_y(img, img_out_y, height, width);
	ScalingImage(4, img_out_x, height, width);
	ScalingImage(4, img_out_y, height, width);

	ImageShow((char*)"input", img, height, width);
	ImageShow((char*)"output(x)", img_out_x, height, width);
	ImageShow((char*)"output(y)", img_out_y, height, width);
}

void MagGradient_xy(int ** img, int height, int width, int** img_out)
{
	for (int y = 0; y < height - 1; y++)
	{
		for (int x = 0; x < width - 1; x++)
		{
			int fy = img[y + 1][x] - img[y][x];
			int fx = img[y][x + 1] - img[y][x];
			img_out[y][x] = abs(fx) + abs(fy);
		}
	}
}

void ex1029_2()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/barbara.png", &height, &width);
	int** img_out = (int**)IntAlloc2(height, width);

	MagGradient_xy(img, height, width, img_out);
	ScalingImage(2, img_out, height, width);

	ImageShow((char*)"input", img, height, width);
	ImageShow((char*)"output", img_out, height, width);
}

void NormalizeImage(int** input, int height, int width, int** output)
{
	int maxvalue = FindMaxValue(input, height, width);

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			output[y][x] = (float)input[y][x] / maxvalue * 255 + 0.5;
		}
	}
}

void ex1029_3()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);
	int** img_out = (int**)IntAlloc2(height, width);

	MagGradient_xy(img, height, width, img_out);
	NormalizeImage(img_out, height, width, img_out);

	ImageShow((char*)"input", img, height, width);
	ImageShow((char*)"output", img_out, height, width);
}

void AbsImage(int** img_in_out, int height, int width)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			img_in_out[y][x] = abs(img_in_out[y][x]);
		}
	}
}

void ex1105_1() //라플라시안
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);
	int** img_out = (int**)IntAlloc2(height, width);
	float** kernel = (float**)FloatAlloc2(3, 3);

#if 0
	kernel[0][0] = 0;
	kernel[0][1] = -1.0;
	kernel[0][2] = 0;
	kernel[1][0] = -1.0;
	kernel[1][1] = 4.0;
	kernel[1][2] = -1.0;
	kernel[2][0] = 0;
	kernel[2][1] = -1.0;
	kernel[2][2] = 0;
#else
	kernel[0][0] = -1.0;
	kernel[0][1] = -1.0;
	kernel[0][2] = -1.0;
	kernel[1][0] = -1.0;
	kernel[1][1] = 8.0;
	kernel[1][2] = -1.0;
	kernel[2][0] = -1.0;
	kernel[2][1] = -1.0;
	kernel[2][2] = -1.0;
#endif

	MaskingImage(kernel, img, height, width, img_out);
	AbsImage(img_out, height, width);
	//ClippingImage(img_out, height, width, img_out);
	NormalizeImage(img_out, height, width, img_out);

	ImageShow((char*)"input", img, height, width);
	ImageShow((char*)"output", img_out, height, width);
}

void MagSobel_x(int** img, int height, int width, int** img_out)
{
	float** kernel = (float**)FloatAlloc2(3, 3);

	kernel[0][0] = -1.0;
	kernel[0][1] = -2.0;
	kernel[0][2] = -1;
	kernel[1][0] = 0;
	kernel[1][1] = 0;
	kernel[1][2] = 0;
	kernel[2][0] = 1;
	kernel[2][1] = 2;
	kernel[2][2] = 1;

	MaskingImage(kernel, img, height, width, img_out);
	AbsImage(img_out, height, width);

	FloatFree2(kernel, 3, 3);
}

void MagSobel_y(int** img, int height, int width, int** img_out)
{
	float** kernel = (float**)FloatAlloc2(3, 3);

	kernel[0][0] = -1.0;
	kernel[0][1] = 0;
	kernel[0][2] = 1.0;
	kernel[1][0] = -2.0;
	kernel[1][1] = 0;
	kernel[1][2] = 2.0;
	kernel[2][0] = -1.0;
	kernel[2][1] = 0;
	kernel[2][2] = 1.0;

	MaskingImage(kernel, img, height, width, img_out);
	AbsImage(img_out, height, width);

	FloatFree2(kernel, 3, 3);
}

void MagSobel(int** img, int height, int width, int** img_out_xy)
{
	int** img_out_x = (int**)IntAlloc2(height, width);
	int** img_out_y = (int**)IntAlloc2(height, width);

	MagSobel_x(img, height, width, img_out_x);
	MagSobel_y(img, height, width, img_out_y);

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			img_out_xy[y][x] = img_out_x[y][x] + img_out_y[y][x];
		}
	}
	IntFree2(img_out_x, height, width);
	IntFree2(img_out_y, height, width);
}

void ex1105_2() //소벨
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/barbara.png", &height, &width);
	int** img_out_xy = (int**)IntAlloc2(height, width);

	MagSobel(img, height, width, img_out_xy);

	//ClippingImage(img_out, height, width, img_out);
	NormalizeImage(img_out_xy, height, width, img_out_xy);

	ImageShow((char*)"input", img, height, width);
	ImageShow((char*)"output", img_out_xy, height, width);
}

void ex1106_1()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);
	int** img_out = (int**)IntAlloc2(height, width);
	float** kernel = (float**)FloatAlloc2(3, 3);

#if 1
	kernel[0][0] = 0;
	kernel[0][1] = -1.0;
	kernel[0][2] = 0;
	kernel[1][0] = -1.0;
	kernel[1][1] = 5.0;
	kernel[1][2] = -1.0;
	kernel[2][0] = 0;
	kernel[2][1] = -1.0;
	kernel[2][2] = 0;
#else
	kernel[0][0] = -1.0;
	kernel[0][1] = -1.0;
	kernel[0][2] = -1.0;
	kernel[1][0] = -1.0;
	kernel[1][1] = 9.0;
	kernel[1][2] = -1.0;
	kernel[2][0] = -1.0;
	kernel[2][1] = -1.0;
	kernel[2][2] = -1.0;
#endif

	MaskingImage(kernel, img, height, width, img_out);
	ClippingImage(img_out, height, width, img_out);

	ImageShow((char*)"input", img, height, width);
	ImageShow((char*)"output", img_out, height, width);
}

void GetKernel_S1(float alpha, float** kernel)
{
	kernel[0][0] = 0;
	kernel[0][1] = -alpha;
	kernel[0][2] = 0;
	kernel[1][0] = -alpha;
	kernel[1][1] = 1.0 + 4 * alpha;
	kernel[1][2] = -alpha;
	kernel[2][0] = 0;
	kernel[2][1] = -alpha;
	kernel[2][2] = 0;
}

void GetKernel_S2(float alpha, float** kernel)
{
	kernel[0][0] = -alpha;
	kernel[0][1] = -alpha;
	kernel[0][2] = -alpha;
	kernel[1][0] = -alpha;
	kernel[1][1] = 1.0 + 8.0 * alpha;
	kernel[1][2] = -alpha;
	kernel[2][0] = -alpha;
	kernel[2][1] = -alpha;
	kernel[2][2] = -alpha;
}

void ex1106_2()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);
	int** img_out = (int**)IntAlloc2(height, width);
	float** kernel = (float**)FloatAlloc2(3, 3);

	float alpha = 0.1;
#if 0
	GetKernel_S1(alpha, kernel);
#else
	GetKernel_S2(alpha, kernel);
#endif

	MaskingImage(kernel, img, height, width, img_out);
	ClippingImage(img_out, height, width, img_out);

	ImageShow((char*)"input", img, height, width);
	ImageShow((char*)"output", img_out, height, width);
}

void ex1106_3()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);
	int** img_out = (int**)IntAlloc2(height, width);
	float** kernel = (float**)FloatAlloc2(3, 3);

	ImageShow((char*)"input", img, height, width);

	for (float alpha = 0.0; alpha <= 1.0; alpha += 0.1)
	{
		GetKernel_S1(alpha, kernel);

		MaskingImage(kernel, img, height, width, img_out);
		ClippingImage(img_out, height, width, img_out);
		ImageShow((char*)"output", img_out, height, width);
	}

}

void Bubbling(int data[], int size)
{

	for (int i = 0; i < size - 1; i++)
	{
		if (data[i] > data[i + 1])
		{
			int tmp = data[i];
			data[i] = data[i + 1];
			data[i + 1] = tmp;
		}
	}
}

void BubbleSort(int data[], int size)
{
	for (int n = 0; n < size - 1; n++)
	{
		Bubbling(data, size - n);
	}
}

#define SIZE 5

void ex1106_4()
{
	int data[SIZE] = { 7, 3, 2, 5, 1 };

	//Bubbling(data, SIZE - 0); //data[SIZE - 1] : 최대값 --> 더 이상 비교할 필요 없음

	//Bubbling(data, SIZE - 1); //data[SIZE - 2] : 2번째 최대값 --> 더 이상 비교할 필요 없음

	//Bubbling(data, SIZE - 2); //data[SIZE - 3] : 3번째 최대값 --> 더 이상 비교할 필요 없음

	//Bubbling(data, SIZE - 3); //data[SIZE - 4] : 4번째 최대값 --> 더 이상 비교할 필요 없음

	BubbleSort(data, SIZE);
}

void GetBlock3x3(int y, int x, int** img, int block1d[])
{
	int index = 0;
	for (int m = -1; m <= 1; m++)
	{
		for (int n = -1; n <= 1; n++)
		{
			block1d[index] = img[y + m][x + n];
			index++;
		}
	}
}

void MedianFiltering(int** img, int height, int width, int** img_out)
{
	for (int y = 1; y < height - 1; y++)
	{
		for (int x = 1; x < width - 1; x++)
		{
			int block[9];
			GetBlock3x3(y, x, img, block);
			BubbleSort(block, 9);
			img_out[y][x] = block[4];
		}
	}
}

void CopyImage(int** src, int height, int width, int** dst)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			dst[y][x] = src[y][x];
		}
	}
}

void ex1112_1()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lenaSP20.png", &height, &width);
	int** img_out = (int**)IntAlloc2(height, width);
	int** img_out2 = (int**)IntAlloc2(height, width);

	MedianFiltering(img, height, width, img_out);
	MedianFiltering(img_out, height, width, img_out2);

	ImageShow((char*)"input", img, height, width);
	ImageShow((char*)"output", img_out, height, width);
	ImageShow((char*)"output2", img_out2, height, width);
}

void ex1112_2()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lenaSP20.png", &height, &width);
	int** img_out = (int**)IntAlloc2(height, width);
	int** img_out2 = (int**)IntAlloc2(height, width);
	int** img_org = (int**)IntAlloc2(height, width);

	ImageShow((char*)"input", img, height, width);
	//img --> img_org copy
	CopyImage(img, height, width, img_org);
	for (int n = 0; n < 5; n++)
	{
		MedianFiltering(img, height, width, img_out);
		CopyImage(img_out, height, width, img);
		ImageShow((char*)"output", img_out, height, width);
	}
}

void MaxFiltering(int** img, int height, int width, int** img_out)
{
	for (int y = 1; y < height - 1; y++)
	{
		for (int x = 1; x < width - 1; x++)
		{
			int block[9];
			GetBlock3x3(y, x, img, block);
			BubbleSort(block, 9);
			img_out[y][x] = block[8];
		}
	}
}

void MinFiltering(int** img, int height, int width, int** img_out)
{
	for (int y = 1; y < height - 1; y++)
	{
		for (int x = 1; x < width - 1; x++)
		{
			int block[9];
			GetBlock3x3(y, x, img, block);
			BubbleSort(block, 9);
			img_out[y][x] = block[0];
		}
	}
}

void ex1112_3()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/bin_numbers.bmp", &height, &width);
	int** img_out = (int**)IntAlloc2(height, width);
	int** img_out2 = (int**)IntAlloc2(height, width);
	int** img_org = (int**)IntAlloc2(height, width);

	CopyImage(img, height, width, img_org);

	MaxFiltering(img, height, width, img_out); //img->img_out
	CopyImage(img_out, height, width, img); //img_out->img
	MaxFiltering(img, height, width, img_out); //img->img_out

	CopyImage(img_org, height, width, img);
	MinFiltering(img, height, width, img_out2);
	CopyImage(img_out2, height, width, img);
	MinFiltering(img, height, width, img_out2);

	ImageShow((char*)"input", img_org, height, width);
	ImageShow((char*)"output", img_out, height, width);
	ImageShow((char*)"output2", img_out2, height, width);
}

void ex1112_4()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/bin_numbers.bmp", &height, &width);
	int** img_out = (int**)IntAlloc2(height, width);
	int** img_out2 = (int**)IntAlloc2(height, width);
	int** img_out3 = (int**)IntAlloc2(height, width);

	MaxFiltering(img, height, width, img_out); 
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			img_out2[y][x] = img_out[y][x] - img[y][x];
		}
	}

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			img_out3[y][x] = img_out2[y][x] + img[y][x];
		}
	}

	ImageShow((char*)"input", img, height, width);
	ImageShow((char*)"output", img_out, height, width);
	ImageShow((char*)"output2", img_out2, height, width);
	ImageShow((char*)"output3", img_out3, height, width);
}

void UpsamplingX2_0order(int** img, int height, int width, int** img_out)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			img_out[2 * y][2 * x] = img[y][x];
			img_out[2 * y][2 * x + 1] = img[y][x];
			img_out[2 * y + 1][2 * x] = img[y][x];
			img_out[2 * y + 1][2 * x + 1] = img[y][x];
		}
	}
}

void UpsamplingX2_1order(int** img, int height, int width, int** img_out)
{
	for (int y = 0; y < height; y++) //(2y, 2x)
	{
		for (int x = 0; x < width; x++)
		{
			img_out[2 * y][2 * x] = img[y][x];
		}
	}

	for (int y = 0; y < height; y++) //(2y, 2x+1)
	{
		for (int x = 0; x < width - 1; x++)
		{
			img_out[2 * y][2 * x + 1] = (img[y][x] + img[y][x + 1]) / 2.0 + 0.5;
		}
	}

	for (int y = 0; y < height - 1; y++) //(2y+1, 2x)
	{
		for (int x = 0; x < width; x++)
		{
			img_out[2 * y + 1][2 * x] = (img[y][x] + img[y + 1][x]) / 2.0 + 0.5;
		}
	}

	int heightx2 = 2 * height;
	int widthx2 = 2 * width;

	for (int yp = 1; yp < heightx2; yp += 2) //(2y+1, 2x+1)
	{
		for (int xp = 1; xp < widthx2; xp += 2)
		{
			img_out[yp][xp] = (img_out[yp][xp - 1] + img_out[yp][xp + 1]) / 2.0 + 5.0;
		}
	}
}

void ex1119_1()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);
	int heightx2 = 2 * height;
	int widthx2 = 2 * width;
	int** img_out_0 = (int**)IntAlloc2(heightx2, widthx2);
	int** img_out_1 = (int**)IntAlloc2(heightx2, widthx2);

	ImageShow((char*)"input", img, height, width);

	UpsamplingX2_0order(img, height, width, img_out_0);
	UpsamplingX2_1order(img, height, width, img_out_1);

	ImageShow((char*)"output1", img_out_0, heightx2, widthx2);
	ImageShow((char*)"output2", img_out_1, heightx2, widthx2);
}

void DownSamplingx2(int** img, int height, int width, int** img_out)
{
	int h_prime = height / 2;
	int w_prime = width / 2;

	for (int y = 0; y < h_prime; y++)
	{
		for (int x = 0; x < w_prime; x++)
		{
			img_out[y][x] = img[2 * y][2 * x];
		}
	}
}

void ex1119_2()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);
	int h_prime = height / 2;
	int w_prime = width / 2;
	int** img_out1 = (int**)IntAlloc2(h_prime, w_prime);
	//int h_q = h_prime / 2;
	//int w_q = w_primte / 2;
	int** img_out2 = (int**)IntAlloc2(h_prime, w_prime);

	DownSamplingx2(img, height, width, img_out1);
	DownSamplingx2(img_out1, h_prime, w_prime, img_out2);

	ImageShow((char*)"input", img, height, width);
	ImageShow((char*)"output1", img_out1, h_prime, w_prime);
	ImageShow((char*)"output2", img_out2, h_prime / 2, w_prime / 2);
	//ImageShow((char*)"output2", img_out2, h_q, w_q);
}

void ex1119_3()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);
	int h_prime = height / 2;
	int w_prime = width / 2;
	int** img_out1 = (int**)IntAlloc2(h_prime, w_prime);
	int h_q = h_prime / 2;
	int w_q = w_prime / 2;
	//int** img_out2 = (int**)IntAlloc2(h_prime, w_prime);
	int** img_out2 = (int**)IntAlloc2(h_q, w_q);

	int** img_mean = (int**)IntAlloc2(height, width);
	meanFilter3x3(img , height, width, img_mean);
	DownSamplingx2(img_mean, height, width, img_out1);

	int** img_mean_h = (int**)IntAlloc2(h_prime, w_prime);
	meanFilter3x3(img_out1, h_prime, w_prime, img_mean_h);
	DownSamplingx2(img_out1, h_prime, w_prime, img_out2);

	ImageShow((char*)"input", img, height, width);
	ImageShow((char*)"output1", img_out1, h_prime, w_prime);
	//ImageShow((char*)"output2", img_out2, h_prime / 2, w_prime / 2);
	ImageShow((char*)"output2", img_out2, h_q, w_q);
}

int BilinearInterpolation(int** img, float y_f, float x_f, int height, int width)
{
	int y = (int)y_f;
	int x = (int)x_f;


	//좌표 y_f, x_f가 영상 바깥인 경우 0을 return
	if (y < 0 || x < 0 || x >= width - 1 || y >= height - 1)
	{
		return 0;
	}
	else
	{
		int y = (int)y_f;
		int x = (int)x_f;
		int A = img[y][x];
		int B = img[y][x + 1];
		int C = img[y + 1][x];
		int D = img[y + 1][x + 1];
		float dx = x_f - x;
		float dy = y_f - y;

		int value = (1 - dx) * (1 - dy) * A + dx * (1 - dy) * B + (1 - dx) * dy * C + dx * dy * D + 0.5;

		return value;
	}
}

void ex1120_1()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);
	int heightx2 = height * 2;
	int widthx2 = width * 2;
	int** img_out = (int**)IntAlloc2(heightx2, widthx2);

	//float y_f = 100.5, x_f = 200.0;
	//int value = BilinearInterpolation(img, y_f, x_f, height, width);

	for (int yp = 0; yp < heightx2; yp++)
	{
		for (int xp = 0; xp < widthx2; xp++)
		{
			float y = yp / 2.0; //0.5, 0.7, 1.2...
			float x = xp / 2.0; //0.5, 0.7, 1.2...

			img_out[yp][xp] = BilinearInterpolation(img, y, x, height, width);
		}
	}

	ImageShow((char*)"input", img, height, width);
	ImageShow((char*)"output", img_out, heightx2, widthx2);
}

void ex1120_2()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);
	int** img_out = (int**)IntAlloc2(height, width);

	double theta = 45.0;
	theta = CV_PI / 180.0 * theta; //degree -> radian

	for (int yp = 0; yp < height; yp++)
	{
		for (int xp = 0; xp < width; xp++)
		{
			float x = cos(theta) * xp + sin(theta) * yp;
			float y = -sin(theta) * xp + cos(theta) * yp;

			img_out[yp][xp] = BilinearInterpolation(img, y, x, height, width);
		}
	}

	ImageShow((char*)"input", img, height, width);
	ImageShow((char*)"output", img_out, height, width);
}

void ex1126_1()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);
	int** img_out = (int**)IntAlloc2(height, width);

	double theta = 25.0;
	theta = CV_PI / 180.0 * theta; //degree -> radian

	int cx = width / 2;
	int cy = height / 2;
	float ratio = 0.6;
	float alpha = 1 / ratio;

	double ctheta = cos(theta);
	double stheta = sin(theta);

	for (int yp = 0; yp < height; yp++)
	{
		for (int xp = 0; xp < width; xp++)
		{
			float x = alpha * ctheta * (xp - cx) + alpha * stheta * (yp - cy) + cx;
			float y = -alpha * stheta * (xp - cx) + alpha * ctheta * (yp - cy) + cy;

			img_out[yp][xp] = BilinearInterpolation(img, y, x, height, width);
		}
	}

	ImageShow((char*)"input", img, height, width);
	ImageShow((char*)"output", img_out, height, width);
}

void ex1126_2()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);
	int** img_out = (int**)IntAlloc2(height, width);

	double a = 1, b = 0, c = 1, d = 1, tx = 0, ty = 0;
	double det = a * d - b * c;
	double ap = d / det;
	double bp = -b / det;
	double cp = -c / det;
	double dp = a / det;

	for (int yp = 0; yp < height; yp++)
	{
		for (int xp = 0; xp < width; xp++)
		{
			float x = ap * (xp - tx) + bp * (yp - ty); 
			float y = cp * (xp - tx) + dp * (yp - ty);

			img_out[yp][xp] = BilinearInterpolation(img, y, x, height, width);
		}
	}

	ImageShow((char*)"input", img, height, width);
	ImageShow((char*)"output", img_out, height, width);
}

double MAD(int** img0, int** img1, int height, int width)
{
	int sad = 0;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			sad = sad + abs(img0[y][x] - img1[y][x]);
		}
	}

	return (double)sad / (width * height);;
}

double MSE(int** img0, int** img1, int height, int width)
{
	int sse = 0;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			sse = sse + (img0[y][x] - img1[y][x]) * (img0[y][x] - img1[y][x]);
		}
	}

	return (double)sse / (width * height);;
}

void ex1126_3()
{
	int height, width;
	int** img0 = ReadImage((char*)"./TestImages/lena.png", &height, &width);
	int** img1 = ReadImage((char*)"./TestImages/barbara.png", &height, &width);
	int** img_out = (int**)IntAlloc2(height, width);

	double mad = MAD(img0, img1, height, width);
	double mse = MSE(img0, img1, height, width);
	printf("\n mad = %f, mse = %f", mad, mse);

	//ImageShow((char*)"input", img1, height, width);
	//ImageShow((char*)"output", img_out, height, width);
}

void ReadBlock(int** img, int yp, int xp, int** block, int by, int bx)
{
	for (int i = 0; i < by; i++)
	{
		for (int j = 0; j < bx; j++)
		{
			block[i][j] = img[yp + i][xp + j];
		}
	}
}

void WriteBlock(int** img, int yp, int xp, int** block, int by, int bx)
{
	for (int i = 0; i < by; i++)
	{
		for (int j = 0; j < bx; j++)
		{
			img[yp + i][xp + j] = block[i][j];
		}
	}
}

void ex1127_1()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);
	int by, bx;
	int** block = ReadImage((char*)"./TestImages/lena_template.png", &by, &bx);
	int** block_img = (int**)IntAlloc2(by, bx);

	int yp = 200, xp = 300;
	ReadBlock(img, yp, xp, block_img, by, bx);
	double mad = MAD(block, block_img, by, bx);
	printf("\n MAD(%d, %d) = %f", yp, xp, mad);

	//ImageShow((char*)"input", img, height, width);
}

void DrawBox(int** img, int yp, int xp, int by, int bx)
{
	//윗쪽 가로선
	for (int x = 0; x < bx; x++)
	{
		img[yp][xp + x] = 255;
	}
	 
	//아랫쪽 가로선
	for (int x = 0; x < bx; x++)
	{
		img[yp + by][xp + x] = 255;
	}

	//왼쪽 세로선
	for (int y = 0; y < by; y++)
	{
		img[yp + y][xp] = 255;
	}

	//오른쪽 세로선
	for (int y = 0; y < by; y++)
	{
		img[yp + y][xp + bx] = 255;
	}
}

void ex1127_2()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/barbara.png", &height, &width);
	int by, bx;
	int** block = ReadImage((char*)"./TestImages/barbara_template.png", &by, &bx);
	int** block_img = (int**)IntAlloc2(by, bx);

	double mad_min = FLT_MAX;
	int yp_min = 0, xp_min = 0;

	for (int yp = 0; yp <= height - by; yp++)
	{
		for (int xp = 0; xp <= width - bx; xp++)
		{
			ReadBlock(img, yp, xp, block_img, by, bx);

			double mad = MAD(block, block_img, by, bx);

			if (mad < mad_min)
			{
				mad_min = mad;
				yp_min = yp;
				xp_min = xp;
			}
		}
	}

	DrawBox(img, yp_min, xp_min, by, bx);

	printf("\n MAD(%d, %d) = %f", yp_min, xp_min, mad_min);

	ImageShow((char*)"input", img, height, width);
}

#define NUM_IMG 510

void ReadDBImages(int*** db, int* pBy, int* pBx)
{
	for (int i = 0; i < NUM_IMG; i++)
	{
		char filename[100];
		sprintf_s(filename, "./db영상(얼굴)/dbs%04d.jpg", i);
		db[i] = (int**)ReadImage(filename, pBy, pBx);
		//ImageShow((char*)"db", db[i], *pBy, *pBx);
	}
}

int FindBestIndex(int** block, int*** db, int num, int by, int bx)
{
	float mad_min = FLT_MAX;
	int index;

	for (int n = 0; n < num; n++)
	{
		float mad = MAD(block, db[n], by, bx);
		if (mad < mad_min)
		{
			mad_min = mad;
			index = n;
		}
	}

	return index;
}

typedef int** INT2;

void ex1203_1()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);
	int** img_out = (int**)IntAlloc2(height, width);

	//얼굴영상 510장 모두 읽기
	int by, bx;
	//int** db = (int**)ReadImage((char*)"./db영상(얼굴)/dbs0000.jpg", &by, &bx);
	//INT2 db[NUM_IMG];
	INT2* db = new INT2[NUM_IMG];
	//INT2* db = (INT2*)malloc(sizeof(INT2)*NUM_IMG)

	ReadDBImages(db, &by, &bx);

	int** block = (int**)IntAlloc2(by, bx);

	for (int y = 0; y < height; y += by)
	{
		for (int x = 0; x < width; x += bx)
		{
			ReadBlock(img, y, x, block, by, bx);

			int index = FindBestIndex(block, db, NUM_IMG, by, bx);

			WriteBlock(img_out, y, x, db[index], by, bx);

		}
	}

	ImageShow((char*)"output", img_out, height, width);

	IntFree2(block, by, bx);
	delete[] db;
}

void main()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);
	int** img_out = (int**)IntAlloc2(height, width);

	//얼굴영상 510장 모두 읽기
	int by, bx;
	//int** db = (int**)ReadImage((char*)"./db영상(얼굴)/dbs0000.jpg", &by, &bx);
	//INT2 db[NUM_IMG];
	//INT2* db = new INT2[NUM_IMG];
	INT2* db = (INT2*)malloc(sizeof(INT2)*NUM_IMG);

	ReadDBImages(db, &by, &bx);

	int sby = by / 2;
	int	sbx = bx / 2;

	//INT2* sdb = new INT2[NUM_IMG];
	INT2* sdb = (INT2*)malloc(sizeof(INT2) * NUM_IMG);
	for (int n = 0; n < NUM_IMG; n++)
	{
		sdb[n] = (int**)IntAlloc2(sby, sbx);
	}

	for (int n = 0; n < NUM_IMG; n++)
	{
		DownSamplingx2(db[n], by, bx, sdb[n]);
	}

	int** block = (int**)IntAlloc2(sby, sbx);

	for (int y = 0; y < height; y += sby)
	{
		for (int x = 0; x < width; x += sbx)
		{
			ReadBlock(img, y, x, block, sby, sbx);

			int index = FindBestIndex(block, sdb, NUM_IMG, sby, sbx);

			WriteBlock(img_out, y, x, sdb[index], sby, sbx);

		}
	}

	ImageShow((char*)"output", img_out, height, width);

	IntFree2(block, sby, sbx);
	for (int n = 0; n < NUM_IMG; n++)
	{
		IntFree2(db[n], by, bx);
	}
	free(db);
	for (int n = 0; n < NUM_IMG; n++)
	{
		IntFree2(sdb[n], by, bx);
	}
	free(sdb);
	//delete[] db;
	//delete[] sdb;
}

void sample()
{
	int height, width;
	int** img = ReadImage((char*)"./TestImages/lena.png", &height, &width);
	int** img_out = (int**)IntAlloc2(height, width);

	ImageShow((char*)"input", img, height, width);
	ImageShow((char*)"output", img_out, height, width);
}