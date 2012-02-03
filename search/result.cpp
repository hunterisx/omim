#include "result.hpp"


namespace search
{

Result::Result(string const & str, string const & region,
               string const & flag, string const & type,
               uint32_t featureType, m2::RectD const & featureRect,
               double distanceFromCenter)
  : m_str(str), m_region(region), m_flag(flag), m_type(type),
    m_featureRect(featureRect), m_featureType(featureType),
    m_distanceFromCenter(distanceFromCenter)
{
  // Features with empty names can be found after suggestion.
  if (m_str.empty())
    m_str = "-";
}

Result::Result(string const & str, string const & suggestionStr)
  : m_str(str), m_suggestionStr(suggestionStr)
{
}

Result::ResultType Result::GetResultType() const
{
  if (!m_suggestionStr.empty())
    return RESULT_SUGGESTION;
  return RESULT_FEATURE;
}

m2::RectD Result::GetFeatureRect() const
{
  ASSERT_EQUAL(GetResultType(), RESULT_FEATURE, ());
  return m_featureRect;
}

m2::PointD Result::GetFeatureCenter() const
{
  ASSERT_EQUAL(GetResultType(), RESULT_FEATURE, ());
  return m_featureRect.Center();
}

double Result::GetDistanceFromCenter() const
{
  ASSERT_EQUAL(GetResultType(), RESULT_FEATURE, ());
  return m_distanceFromCenter;
}

char const * Result::GetSuggestionString() const
{
  ASSERT_EQUAL(GetResultType(), RESULT_SUGGESTION, ());
  return m_suggestionStr.c_str();
}

}  // namespace search
