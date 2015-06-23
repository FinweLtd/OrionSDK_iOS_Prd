Pod::Spec.new do |s|
  s.name = 'OrionSDK'
  s.version = '1.0.0'
  s.license      = {
    :type => 'Copyright',
    :text => <<-LICENSE
      Copyright 2015 Finwe Ltd, Inc. All rights reserved.
      LICENSE
  }
  s.summary = 'OrionSDK_iOS containing components for panorama video'
  s.homepage = 'https://github.com/FinweLtd/OrionSDK_iOS_Prd'
  s.documentation_url = 'https://github.com/FinweLtd/OrionSDK_iOS_Prd/wiki'
  s.author = { 'Hannu Limma' => 'Hannu.Limma@finwe.fi' }
  s.platform = :ios
  s.source = { :git => 'https://github.com/FinweLtd/OrionSDK_iOS_Prd.git', :tag => "#{s.version}" }
  s.source_files = 'OrionSDK/Headers/*.h'
  s.preserve_paths = 'OrionSDK/libOrionSDK.a'
  s.vendored_libraries = 'OrionSDK/libOrionSDK.a'
  s.frameworks = 'UIKit', 'Foundation', 'CoreMotion', 'OpenAL', 'AudioToolbox'
  s.requires_arc = true
  s.library = 'stdc++'
  s.xcconfig = { 'LIBRARY_SEARCH_PATHS' => '"$(PODS_ROOT)/OrionSDK"', 'HEADER_SEARCH_PATHS' => '"${PODS_ROOT}/Headers/OrionSDK"' }
end
