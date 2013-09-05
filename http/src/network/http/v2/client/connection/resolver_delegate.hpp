// Copyright (C) 2013 by Glyn Matthews
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef __NETWORK_HTTP_V2_CLIENT_CONNECTION_RESOLVER_DELEGATE_INC__
#define __NETWORK_HTTP_V2_CLIENT_CONNECTION_RESOLVER_DELEGATE_INC__

#include <cstdint>
#include <string>
#include <functional>
#include <boost/asio/ip/tcp.hpp>
#include <boost/range/iterator_range.hpp>

namespace network {
  namespace http {
    namespace v2 {
      class resolver_delegate {

	resolver_delegate(const resolver_delegate &) = delete;
	resolver_delegate &operator = (const resolver_delegate &) = delete;

      public:

	typedef boost::asio::ip::tcp::resolver resolver;
	typedef resolver::iterator resolver_iterator;
	typedef boost::iterator_range<resolver_iterator> resolver_iterator_range;
	typedef std::function<void (const boost::system::error_code &,
				    boost::iterator_range<resolver_iterator>)> on_resolved_fn;

	resolver_delegate() = default;

	virtual ~resolver_delegate() noexcept { }

	virtual void resolve(const std::string &host, std::uint16_t port, on_resolved_fn on_resolved) = 0;

	virtual void clear_resolved_cache() = 0;

      };
    } // namespace v2
  } // namespace http
} // namespace network

#endif // __NETWORK_HTTP_V2_CLIENT_CONNECTION_RESOLVER_DELEGATE_INC__
