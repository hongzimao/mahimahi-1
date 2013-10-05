/* -*-mode:c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#ifndef DNS_PROXY_HH
#define DNS_PROXY_HH

#include "socket.hh"

class DNSProxy
{
private:
    Socket udp_listener_, tcp_listener_;
    Address udp_target_, tcp_target_;

public:
    DNSProxy( const Address & listen_address, const Address & s_udp_target, const Address & s_tcp_target );

    const Socket & udp_listener( void ) { return udp_listener_; }
    const Socket & tcp_listener( void ) { return tcp_listener_; }

    Socket & mutable_udp_listener( void ) { return udp_listener_; }
    Socket & mutable_tcp_listener( void ) { return tcp_listener_; }

    void handle_udp( void );
    void handle_tcp( void );
};

#endif /* DNS_PROXY_HH */
