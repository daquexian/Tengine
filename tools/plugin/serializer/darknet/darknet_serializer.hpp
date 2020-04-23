#ifndef __DARKNET_SERIALIZER_HPP__
#define __DARKNET_SERIALIZER_HPP__

#include "serializer.hpp"
#include "darknet/te_darknet.hpp"
namespace TEngine {

class DarkNetSerializer : public Serializer
{
public:
    bool LoadModel(const std::vector<std::string>& file_list, StaticGraph* static_graph) override;
    bool LoadModel(const std::vector<const void*>& addr_list, const std::vector<int>& size_list, StaticGraph* graph, bool transfer_mem) override;
    
    unsigned int GetFileNum(void) final
    {
        return 2;
    }

    bool LoadConstTensor(const std::string& fname, StaticTensor* const_tensor) override
    {
        return false;
    }
    bool LoadConstTensor(int fd, StaticTensor* const_tensor) override
    {
        return false;
    }
    DarkNetSerializer(void)
    {
        name_ = "DarkNet";
    }
protected:
    
    bool ConstructGraph(StaticGraph* graph, const void *buf, size_t buflen,list* sections);

};

}    // namespace TEngine

#endif
