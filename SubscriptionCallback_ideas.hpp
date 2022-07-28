/**
 * @brief Current Subscription Callback implementation
 *
 */
class SubscriptionCallback : public SubscriptionInterval, public ListNode<SubscriptionCallback *>
{
public:

	// Register the Callback object to the DeviceNode, and the call() function will be called when it enters callback situation
	bool registerCallback()
	{
		// Some callback processing
	}

	// Call function doesn't do anything
	virtual void call() = 0;
};


/**
 * @brief Subscription Callback improved
 *
 */
class SubscriptionCallback : public SubscriptionInterval, public ListNode<SubscriptionCallback *>
{
public:

	// Register the Callback object to the DeviceNode, and the call() function will be called when it enters callback situation. And add a function pointer to call the specified function optionally.
	bool registerCallback(const void *cb_func(void))
	{
		// Some callback processing
		// Internally cache the callback function pointer <<<<< CHANGED
		_cb_func = cb_func;
	}

	// Callback function called from DeviceNode <<<<< CHANGED
	virtual void call()
	{
		_cb_func();
	}

private:
	void * _cb_func(void) // Callback function pointer that will be executed when the Subscription callback is triggered
};


// How it will be exposed in 'Service' code (Server that replies to the request)
void add (const uORB::Service::add_two_ints::Request &request, uORB::Service::add_two_ints::Response &response)
{
  response->sum = request->a + request->b;
}

// Register a callback
uORB::Service<uORB::Service::add_two_ints> service("add_two_ints", &add);
