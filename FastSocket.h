//
//  FastSocket.h
//  Copyright (c) 2011 Daniel Reese <dan@danandcheryl.com>
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#import <Foundation/Foundation.h>


@interface FastSocket : NSObject {
@protected
	int sockfd;
	NSString *host;
	int port;
	void *buffer;
	void *size;
	int timeout;
	int segmentSize;
}

- (id)initWithHost:(NSString *)host andPort:(int)port;
- (void)buffer:(void **)buf size:(int *)size;

#pragma mark Actions

- (BOOL)connect;
- (BOOL)close;

- (long)sendBytes:(void *)buf count:(long)count;
- (long)receiveBytes:(void *)buf limit:(long)limit;

- (long)sendFile:(NSString *)path;
- (long)receiveFile:(NSString *)path length:(long)length;
- (long)receiveFile:(NSString *)path length:(long)length md5:(NSData **)hash;
- (long)receiveFile:(NSString *)path length:(long)length sha1:(NSData **)hash;

#pragma mark Settings

- (int)timeout;
- (BOOL)setTimeout:(int)seconds;

- (int)segmentSize;
- (BOOL)setSegmentSize:(int)size;

#pragma mark Errors

- (NSError *)lastError;

@end