#pragma once

namespace zRender
{
	struct Param
	{
		zString m_szKey;
		zString m_szVal;
		Param* m_pNext;
	};

	class CCore
	{
	private:
		StrMap m_mpSettings;
		StrMap m_mpValueMap;
	public:
		CCore();
		virtual ~CCore();
		StrMap& GetSettings();

		zString Render(zString p_szTemplate, Param p_Parameters);
		zString Render(zString p_szTemplate);
	private:
		zString GetSetting(zString p_szName) const;
		std::string ReadFile(zString p_szName) const;
		std::string Interpret(std::string p_szStream);
		std::vector<std::string> Parse(const char* p_cszPattern, const std::string& p_crszText) const;
	};
}

EXPORT void SetSetting(zString p_szKey, zString p_szValue);
EXPORT zString GetSetting(zString p_szKey);
EXPORT zString Render(zString p_szTemplate, zRender::Param p_Parameters);