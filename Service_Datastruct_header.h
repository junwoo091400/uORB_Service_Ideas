// build/px4_sitl_default/uORB/services/add_two_ints.h

namespace uORB
{
	namespace Service
	{
		namespace add_two_ints
		{
			// uORB::Service::add_two_ints::Request
			struct Request {
				uint64_t timestamp;
				int64_t a;
				int64_t b;
			}

			// uORB::Service::add_two_ints::Response
			struct Response {
				uint64_t timestamp;
				int64_t sum;
			}
		};
	};
};

// Internal / logged uORB topic name string would be : "add_two_ints::request" and "add_two_ints::response".
// However, the way to refer them in the ORB_ID would be "add_two_ints_request" and "add_two_ints_response", since '::' part proably wouldn't work as enum member of ORB_ID
// For this, ORB_DECLARE() macro needs to be edited so that it can use different ORB name metadata string value (with ::) and ORB_ID enum (without ::).
ORB_DECLARE(add_two_ints::request);
ORB_DECLARE(add_two_ints::response);

void print_message(const orb_metadata *meta, const uORB::Service::add_two_ints::Request& message);
void print_message(const orb_metadata *meta, const uORB::Service::add_two_ints::Response& message);
