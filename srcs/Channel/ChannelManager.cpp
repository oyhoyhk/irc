#include "ChannelManager.hpp"

ChannelManager::~ChannelManager(void) {
    for (channel_iter iter = _channels.begin(); iter != _channels.end(); ++iter)
        delete iter->second;
}

Channel*	ChannelManager::getChannelWithName(const string& name) const {
    channel_const_iter temp = _channels.find(name);
    if (temp == _channels.end()) return NULL;
    return temp->second;
}

void		ChannelManager::addChannel(const string& name) {
    if (getChannelWithName(name)) return;
    _channels[name] = new Channel(name);
}

void		ChannelManager::deleteChannel(const string& name) {
    channel_iter temp = _channels.find(name);
    if (temp == _channels.end()) return;
    delete temp->second;
    _channels.erase(temp);
}