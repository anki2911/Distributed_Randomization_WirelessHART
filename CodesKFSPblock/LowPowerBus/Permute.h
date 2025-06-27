#ifndef PERMUTE_H
#define PERMUTE_H

typedef nx_struct rateMsg {
  nx_int16_t R;
}rateMsg_t;

enum {
  AM_RADIO_COUNT_MSG = 6,
};

/*typedef nx_struct radio_count_msg {
  nx_int32_t Mantissa;
  nx_int32_t Exponent;
  nx_int16_t fid;
} radio_count_msg_t;*/

int16_t HYPERPERIOD = 61;

#endif
