From cf52a40302d0d20ccca22a7a1f53e46ef8abfca8 Mon Sep 17 00:00:00 2001
From: Gabriel Souza Franco <gabrielfrancosouza@gmail.com>
Date: Tue, 28 Oct 2014 15:03:07 -0200
Subject: lib: Change bluetooth.h to compile in strict C

---
 lib/bluetooth.h | 10 +++++-----
 1 file changed, 5 insertions(+), 5 deletions(-)

(limited to 'lib/bluetooth.h')

diff --git a/lib/bluetooth.h b/lib/bluetooth.h
index 61c1f9a..f214d81 100644
--- a/lib/bluetooth.h
+++ b/lib/bluetooth.h
@@ -156,18 +156,18 @@ enum {
 
 /* Bluetooth unaligned access */
 #define bt_get_unaligned(ptr)			\
-({						\
+__extension__ ({				\
 	struct __attribute__((packed)) {	\
-		typeof(*(ptr)) __v;		\
-	} *__p = (typeof(__p)) (ptr);		\
+		__typeof__(*(ptr)) __v;		\
+	} *__p = (__typeof__(__p)) (ptr);	\
 	__p->__v;				\
 })
 
 #define bt_put_unaligned(val, ptr)		\
 do {						\
 	struct __attribute__((packed)) {	\
-		typeof(*(ptr)) __v;		\
-	} *__p = (typeof(__p)) (ptr);		\
+		__typeof__(*(ptr)) __v;		\
+	} *__p = (__typeof__(__p)) (ptr);	\
 	__p->__v = (val);			\
 } while(0)
 
-- 
cgit v1.1

