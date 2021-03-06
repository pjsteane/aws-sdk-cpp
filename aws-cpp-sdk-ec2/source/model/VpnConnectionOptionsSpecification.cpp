﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/ec2/model/VpnConnectionOptionsSpecification.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::Utils::Xml;
using namespace Aws::Utils;

namespace Aws
{
namespace EC2
{
namespace Model
{

VpnConnectionOptionsSpecification::VpnConnectionOptionsSpecification() : 
    m_enableAcceleration(false),
    m_enableAccelerationHasBeenSet(false),
    m_staticRoutesOnly(false),
    m_staticRoutesOnlyHasBeenSet(false),
    m_tunnelInsideIpVersion(TunnelInsideIpVersion::NOT_SET),
    m_tunnelInsideIpVersionHasBeenSet(false),
    m_tunnelOptionsHasBeenSet(false)
{
}

VpnConnectionOptionsSpecification::VpnConnectionOptionsSpecification(const XmlNode& xmlNode) : 
    m_enableAcceleration(false),
    m_enableAccelerationHasBeenSet(false),
    m_staticRoutesOnly(false),
    m_staticRoutesOnlyHasBeenSet(false),
    m_tunnelInsideIpVersion(TunnelInsideIpVersion::NOT_SET),
    m_tunnelInsideIpVersionHasBeenSet(false),
    m_tunnelOptionsHasBeenSet(false)
{
  *this = xmlNode;
}

VpnConnectionOptionsSpecification& VpnConnectionOptionsSpecification::operator =(const XmlNode& xmlNode)
{
  XmlNode resultNode = xmlNode;

  if(!resultNode.IsNull())
  {
    XmlNode enableAccelerationNode = resultNode.FirstChild("EnableAcceleration");
    if(!enableAccelerationNode.IsNull())
    {
      m_enableAcceleration = StringUtils::ConvertToBool(StringUtils::Trim(Aws::Utils::Xml::DecodeEscapedXmlText(enableAccelerationNode.GetText()).c_str()).c_str());
      m_enableAccelerationHasBeenSet = true;
    }
    XmlNode staticRoutesOnlyNode = resultNode.FirstChild("staticRoutesOnly");
    if(!staticRoutesOnlyNode.IsNull())
    {
      m_staticRoutesOnly = StringUtils::ConvertToBool(StringUtils::Trim(Aws::Utils::Xml::DecodeEscapedXmlText(staticRoutesOnlyNode.GetText()).c_str()).c_str());
      m_staticRoutesOnlyHasBeenSet = true;
    }
    XmlNode tunnelInsideIpVersionNode = resultNode.FirstChild("TunnelInsideIpVersion");
    if(!tunnelInsideIpVersionNode.IsNull())
    {
      m_tunnelInsideIpVersion = TunnelInsideIpVersionMapper::GetTunnelInsideIpVersionForName(StringUtils::Trim(Aws::Utils::Xml::DecodeEscapedXmlText(tunnelInsideIpVersionNode.GetText()).c_str()).c_str());
      m_tunnelInsideIpVersionHasBeenSet = true;
    }
    XmlNode tunnelOptionsNode = resultNode.FirstChild("TunnelOptions");
    if(!tunnelOptionsNode.IsNull())
    {
      XmlNode tunnelOptionsMember = tunnelOptionsNode.FirstChild("member");
      while(!tunnelOptionsMember.IsNull())
      {
        m_tunnelOptions.push_back(tunnelOptionsMember);
        tunnelOptionsMember = tunnelOptionsMember.NextNode("member");
      }

      m_tunnelOptionsHasBeenSet = true;
    }
  }

  return *this;
}

void VpnConnectionOptionsSpecification::OutputToStream(Aws::OStream& oStream, const char* location, unsigned index, const char* locationValue) const
{
  if(m_enableAccelerationHasBeenSet)
  {
      oStream << location << index << locationValue << ".EnableAcceleration=" << std::boolalpha << m_enableAcceleration << "&";
  }

  if(m_staticRoutesOnlyHasBeenSet)
  {
      oStream << location << index << locationValue << ".StaticRoutesOnly=" << std::boolalpha << m_staticRoutesOnly << "&";
  }

  if(m_tunnelInsideIpVersionHasBeenSet)
  {
      oStream << location << index << locationValue << ".TunnelInsideIpVersion=" << TunnelInsideIpVersionMapper::GetNameForTunnelInsideIpVersion(m_tunnelInsideIpVersion) << "&";
  }

  if(m_tunnelOptionsHasBeenSet)
  {
      unsigned tunnelOptionsIdx = 1;
      for(auto& item : m_tunnelOptions)
      {
        Aws::StringStream tunnelOptionsSs;
        tunnelOptionsSs << location << index << locationValue << ".TunnelOptions." << tunnelOptionsIdx++;
        item.OutputToStream(oStream, tunnelOptionsSs.str().c_str());
      }
  }

}

void VpnConnectionOptionsSpecification::OutputToStream(Aws::OStream& oStream, const char* location) const
{
  if(m_enableAccelerationHasBeenSet)
  {
      oStream << location << ".EnableAcceleration=" << std::boolalpha << m_enableAcceleration << "&";
  }
  if(m_staticRoutesOnlyHasBeenSet)
  {
      oStream << location << ".StaticRoutesOnly=" << std::boolalpha << m_staticRoutesOnly << "&";
  }
  if(m_tunnelInsideIpVersionHasBeenSet)
  {
      oStream << location << ".TunnelInsideIpVersion=" << TunnelInsideIpVersionMapper::GetNameForTunnelInsideIpVersion(m_tunnelInsideIpVersion) << "&";
  }
  if(m_tunnelOptionsHasBeenSet)
  {
      unsigned tunnelOptionsIdx = 1;
      for(auto& item : m_tunnelOptions)
      {
        Aws::StringStream tunnelOptionsSs;
        tunnelOptionsSs << location <<  ".TunnelOptions." << tunnelOptionsIdx++;
        item.OutputToStream(oStream, tunnelOptionsSs.str().c_str());
      }
  }
}

} // namespace Model
} // namespace EC2
} // namespace Aws
