/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.8.0
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // /home/daveb/Development/LeafletTest/index.html
  0x0,0x0,0x0,0x31,
  0x3c,
  0x68,0x74,0x6d,0x6c,0x3e,0xa,0x20,0x20,0x20,0x20,0x3c,0x68,0x31,0x3e,0x46,0x6f,
  0x6f,0x3c,0x2f,0x68,0x31,0x3e,0xa,0x20,0x20,0x20,0x20,0x3c,0x70,0x3e,0x48,0x45,
  0x4c,0x4c,0x4f,0x3c,0x2f,0x70,0x3e,0xa,0x3c,0x2f,0x68,0x74,0x6d,0x6c,0x3e,0xa,
  
  
};

static const unsigned char qt_resource_name[] = {
  // index.html
  0x0,0xa,
  0xc,0xba,0xf2,0x7c,
  0x0,0x69,
  0x0,0x6e,0x0,0x64,0x0,0x65,0x0,0x78,0x0,0x2e,0x0,0x68,0x0,0x74,0x0,0x6d,0x0,0x6c,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/index.html
  0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x5a,0x81,0x2f,0xbb,0x18,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_resources)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_resources)()
{
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x02, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_resources)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_resources)()
{
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x02, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_resources)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_resources)(); }
   } dummy;
}
