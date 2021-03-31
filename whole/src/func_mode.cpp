#include <sstream>
#include "../../share/inc/_utility.hpp"
#include "../../share/inc/_std_func.hpp"
#include "../inc/ext_var.hpp"

    /*-----------------------------------------------
    ここではorder.jsonから取得したデータをもとにどのような動作を
    行うのかを定義していきます

    (例)
    void pwm(jibiki::ProcOperateAuto *control,
          std::vector<std::string> param,
          size_t seq[])
    {
        std::string name = param[0];
        short tgt_pwm = std::stoi(param[1]);

        if(name == "motor_1")
            g_pwm_tgt[0] = tgt_pwm;
        else if(name == "motor_2")
            g_pwm_tgt[1] = tgt_pwm;
        else
        {
            std::stringstream sstr;
            sstr << __PRETTY_FUNCTION__ << "name が一致しません";
            throw sstr.str();
        }
    }
    -----------------------------------------------*/

void test(jibiki::ProcOperateAuto *control,
          std::vector<std::string> param,
          size_t seq[])
{
    /* パラメータ読み込み */
    size_t wait_time = std::stoi(param[0]);

    printf("[ %d, %d, %d ] start %d[s]\n",
           seq[0], seq[1], seq[2], wait_time);

    /* 指定時間待機 */
    for (size_t i = 0; i < wait_time; ++i)
    {
        /* スレッドの管理 */
        if (!control->manage_thread_int())
            break;

        /* executing_order に書き込む */
        std::stringstream sstr;
        sstr << wait_time - i << " [s]";
        control->set_executing_order(seq, sstr.str());

        /* 待機 */
        jibiki::usleep(1E6);
    }

    printf("\t\t\t[ %d, %d, %d ] finish\n", seq[0], seq[1], seq[2]);

    /* executing_order をクリア */
    control->clear_executing_order(seq);
}

