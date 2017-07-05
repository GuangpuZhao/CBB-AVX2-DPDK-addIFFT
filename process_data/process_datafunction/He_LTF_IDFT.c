#include "../../headers/process_data.h"
#include "../../headers/process.h"
#include "../../headers/globalVarINIT.h"
#include "../../headers/commonStructure.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
///IDFT_X_VHTLTF, X_VHTLTF_CSD, N_STS, Band, SampRate
void He_LTF_IDFT(complex32 **X_VHTLTF_CSD, complex32 **IDFT_X_VHTLTF){
    int i;
    int N_LTF = (!(N_STS&(N_STS-1)))?N_STS:(N_STS+1);
    int DftSize = SampRate/(Band/4)*subcar;

    complex32 *X_freq = (complex32 *)malloc(sizeof(complex32)*subcar);
    complex32 *X_freq_pad = (complex32 *)malloc(sizeof(complex32)*DftSize);
    //complex32 *x_Field = (complex32 *)malloc(sizeof(complex32)*DftSize);
    MKSUREENMEM(X_freq);
    MKSUREENMEM(X_freq_pad);
    //MKSUREENMEM(x_Field);
    memset(X_freq,0,sizeof(complex32)*subcar);
    memset(X_freq_pad,0,sizeof(complex32)*DftSize);
    //memset(x_Field,0,sizeof(complex32)*DftSize);

    complex32 *symbol_data[N_STS];
    for(i=0; i<N_STS; i++)
    {
        symbol_data[i] = (complex32 *)malloc(sizeof(complex32)*DftSize);
        MKSUREENMEM(symbol_data[i]);
        memset(symbol_data[i],0,sizeof(complex32)*DftSize);
    }

    int ind_STS,ind_LTF;
    int temp;
    for(ind_STS=0; ind_STS<N_STS; ind_STS++)
    {
        for(ind_LTF=0; ind_LTF<N_LTF; ind_LTF++)
        {
            memcpy(X_freq,&(X_VHTLTF_CSD[ind_STS][subcar*ind_LTF]),sizeof(complex32)*subcar);
            ///Ԥ����
            switch(Band)
            {
                case 40:
                    for(i=64; i<subcar; i++){
                        temp = X_freq[i].real;
                        X_freq[i].real = -1*X_freq[i].imag;
                        X_freq[i].imag = temp;
                    }
                    break;
                case 80:
                    for(i=64; i<subcar; i++){
                        X_freq[i].imag = -1*X_freq[i].imag;
                        X_freq[i].real = -1*X_freq[i].real;
                    }
                    break;
                case 160:
                    for(i=64; i<256; i++){
                        X_freq[i].imag = -1*X_freq[i].imag;
                        X_freq[i].real = -1*X_freq[i].real;
                    }
                    for(i=320; i<subcar; i++){
                        X_freq[i].imag = -1*X_freq[i].imag;
                        X_freq[i].real = -1*X_freq[i].real;
                    }
                    break;
            }

            ///����������ʲ�ͬʱ��IDFT��С�����ز���Ŀ���ȣ��轫���ݷ����м�
            ///����Bandָac�ı�׼��ax����4
            if(SampRate > Band/4)
            {
                int n_pad = DftSize - subcar;
                //for(i=0;i<n_pad/2;i++)
                //    X_freq_pad[i] = 0;
                for(i=n_pad/2;i<n_pad/2+subcar;i++)
                    X_freq_pad[i] = X_freq[i-n_pad/2];
                //for(i=n_pad/2+subcar;i<n_pad+subcar;i++)
                //    X_freq_pad[i] = 0;
            }
            ifftShiftandIFFTData(X_freq_pad,&(IDFT_X_VHTLTF[ind_STS][DftSize*ind_LTF]));
        }//for(ind_LTF=0; ind_LTF<N_LTF; ind_LTF++)
        //addCPforData(&symbol_data,&trans_data,N_SYM,symbol);
    }//for(ind_STS=0; ind_STS<N_STS; ind_STS++)

    free(X_freq);
    free(X_freq_pad);
    for(i=0; i<N_STS; i++) free(symbol_data[i]);
}
