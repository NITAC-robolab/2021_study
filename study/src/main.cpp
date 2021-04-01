#include "../../share/inc/_serial_communication.hpp"
#include "../../share/inc/_picojson.hpp" 
#include "../../share/inc/module.hpp"

int main(void)
{
    try
    {

        jibiki::ParamCom com("/dev/serial/by-id/usb-FTDI_FT232R_USB_UART_A600W703-if00-port0", 5, 1, B57600, "com_pwm_control", true); 
    
        jibiki::ShareVar<int8_t> pwm(0);

        while (1)
        {
            /* キー入力 */
            if (jibiki::kbhit())
            {
                switch (getchar())
                {
                case 'u':
                    pwm += 10;
                    break;
                case 'd':
                    pwm -= 10;
                    break;
                case 'q':
                    return 0;
                }
                printf("%d\n", pwm.read());
            }

            /* 送信 */
            com.tx(1) = pwm.read();
            com.tx(2) = pwm.read();
            com.send();
        }

       
    }
   
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
    return 0;
}