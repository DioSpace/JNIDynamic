#include "jni.h"
void func1(JNIEnv *env, jobject jobject) {
    printf("dynamicNative1  func1\n");
}
jstring func2(JNIEnv *env, jobject jobject) {
    return (*env)->NewStringUTF(env, "hello everybody 2");
}

static const char *mClassName = "register/DynamicRegister";
//三个参数，java层函数名,java 层方法签名,C 层方法指针
//获取签名方法: javap -s -p DynamicRegister.class
static const JNINativeMethod mMethods[]={
        {"dynamicFunc1","()V",(void*)func1},
        {"dynamicFunc2","()Ljava/lang/String;",(void*)func2},
};
//java层load时，便会自动调用该方法
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *reserved){
    printf("hello dynamic0 == 17\n");
    JNIEnv* env = NULL;
//获得 JniEnv
    int r = (*vm)->GetEnv(vm,(void**)&env,JNI_VERSION_1_8);
    if(r != JNI_OK){
        return  -1;
    }
    //FindClass,反射,通过类的名字反射出一个人
    jclass mainActivityCls = (*env)->FindClass(env, mClassName);//注册 如果小于0则注册失败
    r = (*env)->RegisterNatives(env,mainActivityCls,mMethods,2);
    if(r != JNI_OK){
        return -1;
    }
    printf("hello dynamic == 29\n");
    return JNI_VERSION_1_8;
}