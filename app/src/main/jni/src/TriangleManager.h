#pragma once
#include <time.h>
#include <math.h>
#include <android/log.h>
#include <EGL/egl.h>
#include <GLES/gl.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <android/native_window_jni.h>
#include "Singleton.h"
#include "glm.hpp"
#include "ext.hpp"
#include <thread>
#include "JniHelper.h"
class TriangleManager : public Singleton<TriangleManager> {
public:
    TriangleManager();
    ~TriangleManager();
    void                        onCreate();
    void                        onResume();
    void                        onPause();
    void                        onStop();
    void                        onDestroy();
    void                        initGL(int widgetWidth, int widgetHeight);
    void                        drawFrame();
    void                        onChange(int widgetWidth, int widgetHeight);
    void                        setAssetsBmp(AAssetManager* mgr, const char* fileName);
    GLint                       getCameraTextureId();

private:
    int                         _widgetWidth;
    int                         _widgetHeight;
    GLuint                      _sProgramPlay;
    GLuint						_vaoId;
    GLuint						_vboBuffer;
    GLuint                      _textureId;
    GLint						_positionLoc;
    GLint						_textCoordLoc;
    GLint						_mvpMatrixLoc;
    GLint                       _sampler2DLoc;
    glm::mat4                   _mvpMatrix;
    glm::mat4                   _modelMatrix;
    glm::mat4                   _viewMatrix;
    glm::mat4                   _projectionMatrix;
    uint8_t*                    _bmpBuffer;
};