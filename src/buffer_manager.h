#ifndef BUFFERMANAGER_H
#define BUFFERMANAGER_H

#include "buffer_pool.h"
#include "file.h"
/**
 * @brief Buffer Manager class
 * Buffer Manager class is a class that manages the buffer pool
 * It has a block handler class
 * It communicate with disk to read and write data
 */
class BufferManager
{
    private:
        BufferPool *bufferPool;
        std::string file_;
    public:
        BufferManager()
            :bufferPool(new BufferPool())
        {}
        ~BufferManager();
        std::shared_ptr<Page> GetPageFromDisk(PageDirectory &dir,unsigned int pageIdx);
        std::shared_ptr<Page> GetPageFromBufferPool(std::string fileName,unsigned int pageIdx);
        std::shared_ptr<Page> GetEnoughSpacePage(std::string fileName,int length);

        void WriteBlock(std::shared_ptr<Page> page,const char *content,int length);
        void FlushPageToDisk(PageDirectory dir, const std::shared_ptr<Page> &page);

        void PromotePage(std::shared_ptr<Page> page);
        void SetFile(std::string fileName){file_=fileName;}
        void DebugAllBufferPool();
        void DebugTableBufferPool(std::string fileName);
        void DebugTableBufferPool(std::string fileName,int pageIdx);

        
};

#endif