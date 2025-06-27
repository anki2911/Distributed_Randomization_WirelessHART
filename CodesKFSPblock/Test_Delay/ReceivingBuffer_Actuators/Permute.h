#ifndef PERMUTE_H
#define PERMUTE_H

typedef nx_struct radio_count_msg {
  nx_int32_t Mantissa;
  nx_int32_t Exponent;
  nx_int16_t fid;
} radio_count_msg_t;

enum {
  AM_RADIO_COUNT_MSG = 6,
};

typedef nx_struct rateMsg {
  nx_int16_t R;
}rateMsg_t;

typedef nx_struct slot_info {
  nx_uint16_t fid;
  nx_uint16_t s;
  nx_uint16_t r;
  //nx_uint16_t rate;
}slot_info_t;

int HYPERPERIOD = 65;
int NUM_OF_FLOWS = 1;
int NUM_OF_CLUSTERS = 1;
int NUM_OF_CONTROLS = 1;

typedef nx_struct Control_Loop {
	nx_uint16_t period;
	nx_uint16_t available_periods[4];
}Control_Loop_t;

typedef nx_struct Cluster {
  nx_uint16_t cl_id;
  nx_uint16_t period;
  nx_uint16_t key[16];
  nx_int16_t key_length;
  nx_uint16_t util;
  nx_uint16_t slots[65];
  //nx_uint16_t plain[65];
  //nx_uint16_t slot_list[64];
}Cluster_t;

typedef nx_struct Flow {
  nx_uint16_t flow_id;
  nx_uint16_t cntl_ID;
  nx_uint16_t cluster_id;
  nx_uint16_t period;
  nx_uint16_t n_inst;
  nx_uint16_t n_hops;
  nx_uint16_t route[4][2];
}Flow_t;

#endif
