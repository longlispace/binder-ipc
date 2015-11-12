LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)
LOCAL_SRC_FILES:= ExampleService.cpp
LOCAL_C_INCLUDES := $(JNI_H_INCLUDE)
LOCAL_SHARED_LIBRARIES := libutils \
                          libbinder

LOCAL_LDLIBS := -lm -llog 
LOCAL_PRELINK_MODULE := false
LOCAL_MODULE := libExample
include $(BUILD_SHARED_LIBRARY)
include $(call all-makefiles-under, $(LOCAL_PATH))

