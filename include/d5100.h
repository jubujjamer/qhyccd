/// @source      Client.h
/// @description Public interface for class Client.
//  See licensing information in the file README.TXT.

// -----------------------------------------------------------------------------
#ifndef __CLIENT_H__
#define __CLIENT_H__
// -----------------------------------------------------------------------------

// includes

#include <stdlib.h>  // getenv (client_setLogDir)

// -----------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
// -----------------------------------------------------------------------------

extern __declspec(dllexport) void SetIPAddress(char *address);
extern __declspec(dllexport) int init_Cam(void *information);
extern __declspec(dllexport) int  set_Cam(int sc1,int sc2,int sc3);
extern __declspec(dllexport) int  start_Cap();
extern __declspec(dllexport) int  get_Img(unsigned char *ImageData);
extern __declspec(dllexport) int  reset_Cam();
extern __declspec(dllexport) int  cam_PowerOff();
extern __declspec(dllexport) int  get_PackegeNum(unsigned int *num);
extern __declspec(dllexport) int  getOnePackege(unsigned char *onePackege);
extern __declspec(dllexport) int  free_Cam();


// -----------------------------------------------------------------------------
#ifdef __cplusplus
} // #ifdef __cplusplus
#endif
// -----------------------------------------------------------------------------
#endif // __CLIENT_H__
// -----------------------------------------------------------------------------
