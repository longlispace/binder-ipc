#include "ExampleService.h"
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <android/log.h>

namespace android{
    static struct sigaction oldact;
    static pthread_key_t sigbuskey;

    int ExampleService::instantiate(){
        ALOGE("longli: ExampleService instantiate!");
        int r = defaultServiceManager()->addService(String16("longli.example"), new ExampleService());
        ALOGE("longli: Add service return %d/n", r);
        return r;
    }

    ExampleService::ExampleService(){
        ALOGE("longli: ExampleService construct!");
        mNextConnId = 1;
        pthread_key_create(&sigbuskey, NULL);
    }

    ExampleService::~ExampleService(){
        pthread_key_delete(sigbuskey);
        ALOGE("longli: ExampleService destroyed!");
    }

    status_t ExampleService::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags){
        switch(code){
            case 0:{
                pid_t pid = data.readInt32();
                int num = data.readInt32();
                num = num + 100;
                reply->writeInt32(num);
                return NO_ERROR;
                break;
            }
            default:
                return BBinder::onTransact(code, data, reply, flags);
        }
    }
};
