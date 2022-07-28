// build/px4_sitl_default/msg/services_sources/add_two_ints.cpp

// Fields definition for the ORB metadata (used for uLog)
constexpr char __orb_add_two_ints_request_fields[] = "\x89 timestamp;\x85 a;\x85 b;";
constexpr char __orb_add_two_ints_response_fields[] = "\x89 timestamp;\x85 sum;";

// Define (instantiate) the ORB metadata
ORB_DEFINE(add_two_ints::request, struct uORB::Service::add_two_ints::Request, 24, __orb_add_two_ints_request_fields, static_cast<uint8_t>(ORB_ID::add_two_ints_request));
ORB_DEFINE(add_two_ints::response, struct uORB::Service::add_two_ints::Response, 16, __orb_add_two_ints_response_fields, static_cast<uint8_t>(ORB_ID::add_two_ints_response));

void print_message(const orb_metadata *meta, const uORB::Service::add_two_ints::Request& message)
{
	if (sizeof(message) != meta->o_size) {
		printf("unexpected message size for %s: %zu != %i\n", meta->o_name, sizeof(message), meta->o_size);
		return;
	}
	orb_print_message_internal(meta, &message, true);
}

void print_message(const orb_metadata *meta, const uORB::Service::add_two_ints::Response& message)
{
	if (sizeof(message) != meta->o_size) {
		printf("unexpected message size for %s: %zu != %i\n", meta->o_name, sizeof(message), meta->o_size);
		return;
	}
	orb_print_message_internal(meta, &message, true);
}
