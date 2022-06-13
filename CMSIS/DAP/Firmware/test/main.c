
#include <stdio.h>

#include "DAP_config.h"
#include "DAP.h"

union dap_ret
{
  unsigned int data;
  struct {
    unsigned short resp_size;
    unsigned short req_size;
  };
} dap_ret;

void dap_exec(const char* test_rx_data) {
    static char test_tx_data[DAP_PACKET_SIZE];

    dap_ret.data = DAP_ExecuteCommand(test_rx_data, test_tx_data);
    printf("req[%02x] %d bytes, resp %d bytes.\n", test_rx_data[0], dap_ret.req_size, dap_ret.resp_size);
}

void dap_connect_swd() {
    const char test_rx_data[] = {0x02, 0x01};
    dap_exec(test_rx_data);
}

void dap_transfer() {
    const char test_rx_data[] = {0x05, 0x00, 0x01, 0x02};
    dap_exec(test_rx_data);
}

int main() { 
    DAP_Setup();

    // connect to cmsisdap in sed mode
    dap_connect_swd();
    // trig transfer data in swd
    dap_transfer();

    return 0;
}