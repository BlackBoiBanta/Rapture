#pragma once
#include "Event.h"

namespace Rapture
{
	class RAPT_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(RAPT_UINT width, RAPT_UINT height)
			:m_width(width), m_height(height) {}

		inline RAPT_UINT getWidth() { return m_width; }
		inline RAPT_UINT getHeight() { return m_height; }

		SET_EVENT_CATEGS(ApplicationCateg);
		SET_EVENT_TYPE(WindowResize);

	private:
		RAPT_UINT m_width;
		RAPT_UINT m_height;
	};

	class RAPT_API WindowCloseEvent : Event
	{
	public:
		WindowCloseEvent() = default;

		SET_EVENT_CATEGS(ApplicationCateg);
		SET_EVENT_TYPE(WindowClose);
	};

	class RAPT_API AppTickEvent : Event
	{
	public:
		AppTickEvent() = default;

		SET_EVENT_CATEGS(ApplicationCateg);
		SET_EVENT_TYPE(AppTick);
	};

	class RAPT_API AppUpdateEvent : Event
	{
	public:
		AppUpdateEvent() = default;

		SET_EVENT_CATEGS(ApplicationCateg);
		SET_EVENT_TYPE(AppUpdate);
	};

	class RAPT_API AppRenderEvent : Event
	{
	public:
		AppRenderEvent() = default;

		SET_EVENT_CATEGS(ApplicationCateg);
		SET_EVENT_TYPE(AppRender);
	};





}

