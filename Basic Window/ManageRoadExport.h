#pragma once

typedef enum tLANE_TYPE
{
	LANE_TYPE_NONE = 0,
	LANE_TYPE_STRAIGHT = 1,
	LANE_TYPE_CURVATURE = 2
}LANE_TYPE_t;

typedef struct tLane
{
	uint64_t u64LaneID;
	LANE_TYPE_t eLaneType;
	float64_t f64Curvature;
	float64_t f64Width_m;
	f64POINT2D_t stLaneCenterPos[MAX_NUM_LANE_PNT];
	int32_t s32NumOfLaneCenterPnt;
	f64POINT2D_t stLaneSideLeftPos[MAX_NUM_LANE_PNT];
	int32_t s32NumOfLaneSideLeftPnt;
	f64POINT2D_t stLaneSideRightPos[MAX_NUM_LANE_PNT];
	int32_t s32NumOfLaneSideRightPnt;
}Lane_t;


typedef struct tRoad
{
	int8_t s8Valid;
	int32_t s32NumOfLane;
	Lane_t arstLaneSet[MAX_NUM_LANE_IN_ROAD];
}Road_t;