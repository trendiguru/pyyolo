#ifndef LIBYOLO_H
#define LIBYOLO_H
#include "./darknet/src/image.h"

typedef void* yolo_handle;

typedef struct {
	char name[32];
	int left;
	int right;
	int top;
	int bottom;
	float conf;
} detection_info;

yolo_handle yolo_init(char *datacfg, char *cfgfile, char *weightfile);
void yolo_cleanup(yolo_handle handle);
detection_info **yolo_detect(yolo_handle handle, image im, float thresh, float hier_thresh, int *num);
detection_info **yolo_test(yolo_handle handle, char *filename, float thresh, float hier_thresh, int *num);

#endif // LIBYOLO_H
